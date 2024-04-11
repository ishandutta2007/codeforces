#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c], spec[c];
long long ert[c][3], fen[c][3], mod=1e9+7;
vector<pair<int, int> > sz;
vector<int> v;
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b, int c) {
    while (a<=n) {
        fen[a][b]=(fen[a][b]+c)%mod;
        a+=lsb(a);
    }
}
long long ask(int a, int b) {
    long long sum=0;
    while (a) {
        sum=(sum+fen[a][b])%mod;
        a-=lsb(a);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back({x, i});
        }
        sort(sz.begin(), sz.end());
        int cnt=0;
        for (int i=0; i<n; i++) {
            if (i==0 || sz[i].first!=sz[i-1].first) {
                cnt++;
            }
            t[sz[i].second]=cnt;
        }

        for (int i=1; i<=n; i++) {
            ert[i][0]=ask(t[i]-1, 0)+1;
            add(t[i], 0, ert[i][0]);
            while (v.size()>0 && t[i]>=t[v.back()]) {
                spec[v.back()]=0;
                v.pop_back();
            }
            spec[i]=1;
            v.push_back(i);
        }
        reverse(v.begin(), v.end());
        int si=v.size();
        for (int i=n; i>=1; i--) {
            ert[i][1]=(ask(n, 1)-ask(t[i], 1)+mod+1)%mod;
            add(t[i], 1, ert[i][1]);
            int lo=-1, hi=si, mid;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (t[i]<t[v[mid]]) {
                    hi=mid;
                } else {
                    lo=mid;
                }
            }
            if (spec[i]) {
                ert[i][2]=1;
                add(t[i], 2, 1);
            } else if (hi<si && i<v[hi]) {
                ert[i][2]=(ask(t[v[hi]]-1, 2)-ask(t[i], 2)+1);
                add(t[i], 2, ert[i][2]);
            } else {
                ert[i][2]=1;
            }
        }
        long long sum=0;
        for (int i=1; i<=n; i++) {
            sum+=(ert[i][0])*(ert[i][1]-ert[i][2]+mod)%mod;
        }
        cout << sum%mod << "\n";

        for (int i=0; i<=n; i++) {
            for (int j=0; j<=3; j++) {
                fen[i][j]=0, ert[i][j]=0;
            }
            t[i]=0, spec[i]=0;
        }
        sz.clear(), v.clear();
    }
    return 0;
}