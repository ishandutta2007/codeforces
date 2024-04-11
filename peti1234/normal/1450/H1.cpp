#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, m, fakt[c], inv[c], mod=998244353, od, ed, ok, ek, ossz, kdb, ndb, ksum, nsum, sum;
vector<pair<int, pair<bool, long long> > > sz[2];
string s;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<b || b<0) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=0; i<n; i++) {
        if (s[i]=='w') {
            if (i%2) od++;
            else ed++;
        }
        if (s[i]=='?') {
            if (i%2) ok++;
            else ek++;
        }
    }
    //cout << od << " " << ed << " " << ok << " " << ek << endl;
    ossz=ok+ek;
    for (int i=0; i<=ok; i++) {
        long long s=alatt(ok, i);
        sz[(od+i)%2].push_back({od+i, {0, s}});
    }
    for (int i=0; i<=ek; i++) {
        long long s=alatt(ek, i);
        sz[(ed+i)%2].push_back({ed+i, {1, s}});
    }
    //cout << "vege " << sz[0].size() << " " << sz[1].size() << endl;
    for (int j=0; j<2; j++) {
        sort(sz[j].begin(), sz[j].end());
        kdb=0, ksum=0, ndb=0, nsum=0;
        for (int i=0; i<sz[j].size(); i++) {
            if (sz[j][i].second.first) {
                long long se=sz[j][i].second.second;
                ndb+=se;
                nsum+=se*sz[j][i].first, nsum%=mod;
            }
        }
        for (int i=0; i<sz[j].size(); i++) {
            long long ert=sz[j][i].first, p=sz[j][i].second.first, db=sz[j][i].second.second;
            if (p==1) {
                long long se=db;
                ndb-=se, kdb+=se;
                nsum-=se*ert, nsum%=mod;
                ksum+=se*ert, ksum%=mod;
            } else {
                //cout << "valt " << i << " " << kdb << " " << ksum << endl;
                sum+=(kdb*ert-ksum+nsum-ndb*ert)%mod*db;
                sum%=mod;
            }
        }
    }
    for (int i=1; i<=ossz; i++) {
        sum*=inv[2], sum%=mod;
    }
    cout << (sum+mod)%mod << "\n";
    return 0;
}
/*
8 0
bwbb?www
*/