#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, k, t[c], t2[c], kom[c], fel[c], szint[c], sum, kezd, veg;
map<pair<int, int>, vector<int> > m;
void lep(int ut, int st, int spec) {
    bool valt=0;
    int dif=-st;
    cout << ut << " ";
    cout << t2[ut]+st << " ";
    t2[ut]+=st;

    for (int i=1; i<=k; i++) {
        int pos=(ut+i)%n;
        if (pos==spec) {
            valt=1;
            dif=0;
        }
        if (valt) {
            cout << t2[pos] << " ";
        } else {
            if (i<k) {
                cout << sum << " ";
                dif+=t2[pos]-sum;
                t2[pos]=sum;
            } else {
                cout << t2[pos]+dif << " ";
                t2[pos]+=dif;
            }
        }
    }
    cout << "\n";

}
void solve(int a, int b) {
    a%=n, b%=n;
    if (b==(a+1)%n) {
        return;
    }
    vector<int> dif;
    dif.push_back(sum-t2[a]);
    int st=0, ut=a, ert=t2[a]-sum;
    for (int i=(a+1)%n; ; i=(i+1)%n) {
        ert+=t2[i]-sum;
        st++;
        if (st==k && ert>=0 || i==b) {
            while (dif.size()>0) {
                lep(ut, dif.back(), b);
                dif.pop_back();
                ut-=k;
                if (ut<0) {
                    ut+=n;
                }
            }
            if (i!=b) {
                solve(i, b);
            }
            return;
        }
        if (st==k) {
            ut=i, st=0;
            dif.push_back(-ert);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    k--;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        t2[i-1]=t[i];
        sum+=t[i];
    }
    sum/=n;
    for (int i=1; i<=n; i++) {
        kom[i]=kom[i-1]+t[i]-sum;
        int mar=(i+k-1)%k, el=(i+2*k-2)%k;
        for (auto x:m[{kom[i], el}]) {
            fel[x]=i;
        }
        m[{kom[i], el}].clear();
        m[{kom[i], mar}].push_back(i);
    }

    for (int i=n; i>=1; i--) {
        szint[i]=szint[fel[i]]+1;
        if (szint[i]>szint[kezd]) {
            kezd=i;
        }
    }
    cout << (n-szint[kezd]+k-1)/k << "\n";
    veg=kezd;
    while (fel[kezd]) {
        solve(kezd, fel[kezd]);
        kezd=fel[kezd];
    }
    solve(kezd, veg);
    return 0;
}