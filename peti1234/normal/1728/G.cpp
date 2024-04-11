#include <bits/stdc++.h>

using namespace std;
const int c=300005, k=1<<16;
long long dp[k], dp2[c], ert[18][18], d, n, m, t[c], pos[18], mod=998244353;
long long po(long long a, long long p) {
    long long ans=1;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> d >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    pos[0]=-d-1;
    for (int i=1; i<=m; i++) {
        cin >> pos[i];
    }
    sort(pos+1, pos+m+1);
    pos[m+1]=2*d+1;

    for (int bal=0; bal<=m+1; bal++) {
        for (int jobb=bal+1; jobb<=m+2; jobb++) {
            int kis=pos[bal], nagy=pos[jobb];
            ert[bal][jobb]=1;
            for (int i=1; i<=n; i++) {
                if (kis<=t[i] && t[i]<=nagy) {
                    long long x=min({t[i]-kis, nagy-t[i], d+1});
                    ert[bal][jobb]=(ert[bal][jobb]*x)%mod;
                }
            }
        }
    }
    for (int mask=0; mask<(1<<m); mask++) {
        vector<int> p;
        p.push_back(0);
        for (int i=0; i<m; i++) {
            if (mask & (1<<i)) {
                p.push_back(i+1);
            }
        }
        p.push_back(m+1);
        int si=p.size();
        dp[mask]=1;
        for (int i=0; i+1<si; i++) {
            dp[mask]=dp[mask]*ert[p[i]][p[i+1]]%mod;
        }
        //cout << "alap " << mask << " " << dp[mask] << "\n";
    }
    for (int mask=0; mask<(1<<m); mask++) {
        dp2[mask]=po(d+1, n);
        for (int kov=mask; kov; kov=((kov-1) & mask)) {
            int pc=__builtin_popcount(kov);
            if (pc%2) dp2[mask]=(dp2[mask]+mod-dp[kov])%mod;
            else dp2[mask]=(dp2[mask]+dp[kov])%mod;
        }
        //cout << "fontos " << mask << " " << dp2[mask] << "\n";
    }

    int q;
    cin >> q;
    while (q--) {
        int x, mask=(1<<m)-1;
        cin >> x;
        vector<pair<int, int> > sz;
        for (int i=1; i<=m; i++) {
            sz.push_back({abs(x-pos[i]), i-1});
        }
        sort(sz.begin(), sz.end());
        long long ans=dp2[mask]*(d+1)%mod, el=dp2[mask];
        for (auto p:sz) {
            mask-=(1<<p.second);
            ans=(ans+(dp2[mask]-el+mod)*(d+1-p.first))%mod;
            el=dp2[mask];
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
6 1 2
4
2 5
2
1 3
*/