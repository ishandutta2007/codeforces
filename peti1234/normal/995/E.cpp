#include <bits/stdc++.h>

using namespace std;
long long kezd, veg, mod, n=18;
set<pair<long long, int> > s;
vector<int> ans;
long long inv(long long a) {
    if (a<0) a+=mod;
    if (a>=mod) a-=mod;
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) ans=ans*a%mod;
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
void pb(int a) {
    ans.push_back(a);
}
void print() {
    cout << ans.size() << "\n";
    long long aa=kezd, db=0;
    for (auto x:ans) {
        cout << x << " ";
        db++;
        if (x==1) aa=(aa+1)%mod;
        if (x==2) aa=(aa+mod-1)%mod;
        if (x==3) aa=inv(aa);
    }
    cout << "\n";
}
void solve(int a, int b, int dif) {
    for (int i=0; i<n; i++) {
        if (a & (1<<i)) pb(1);
        else pb(2);
        pb(3);
    }
    for (int i=1; i<=abs(dif); i++) {
        pb(dif>0 ? 2 : 1);
    }
    for (int i=n-1; i>=0; i--) {
        pb(3);
        if (b & (1<<i)) pb(2);
        else pb(1);
    }
    print();
    exit(0);
}
int main()
{
    cin >> kezd >> veg >> mod;
    s.insert({-1000, -1}), s.insert({mod+1000, -1});
    for (int i=0; i<(1<<n); i++) {
        long long ert=kezd;
        for (int j=0; j<n; j++) {
            if (i & (1<<j)) ert++;
            else ert--;
            ert=inv(ert);
        }
        s.insert({ert, i});
    }
    for (int i=0; i<(1<<n); i++) {
        long long ert=veg;
        for (int j=0; j<n; j++) {
            if (i & (1<<j)) ert++;
            else ert--;
            ert=inv(ert);
        }
        auto it=s.upper_bound({ert, -1});
        int dif=(*it).first-ert;
        if (abs(dif)<=120) {
            solve((*it).second, i, dif);
        }
        it--;
        dif=(*it).first-ert;
        if (abs(dif)<=120) {
            solve((*it).second, i, dif);
        }
    }
    return 0;
}