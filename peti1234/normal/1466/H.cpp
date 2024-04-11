#include <bits/stdc++.h>

using namespace std;
const int c=42, st=1505;
long long dp[st][c], db[st], fakt[c], inv[c], mo[c], sum, mod=1000000007;
int n, korhossz, t[c], kordb[c], cnt=1;
vector<int> kor;
vector<pair<int, long long> > sz[st];
bool v[c];
void dfs(int a) {
    korhossz++;
    v[a]=true;
    if (!v[t[a]]) {
        dfs(t[a]);
    }
}
vector<int> konv(int ert) {
    vector<int> ans;
    for (int i=0; i<kor.size(); i++) {
        int s=kordb[kor[i]]+1;
        ans.push_back(ert%s);
        ert/=s;
    }
    return ans;
}
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
    if (a<b || a<b) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
long long calc(int kor, int tilos, int kell) {
    if (kell==0) {
        kell=-kor-tilos;
    }
    long long x=(fakt[n]*mo[kor+tilos])%mod, y=fakt[n]*mo[kor+tilos+kell]%mod;
    long long s1=1, s2=1;
    for (int i=1; i<=kor; i++) {
        s1*=x, s2*=y;
        s1%=mod, s2%=mod;
    }
    return (s1-s2+mod)%mod;
}
long long solve(int mask, int ossz, int spec) {
    long long ans=1;
    vector<int> s=konv(mask);
    for (int i=0; i<kor.size(); i++) {
        long long ert=calc(kor[i], ossz-kor[i], spec);
        for (int j=0; j<s[i]; j++) {
            ans*=ert;
            ans%=mod;
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
        mo[i]=oszt(i);
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
        }
        kordb[korhossz]++;
        korhossz=0;
    }
    for (int i=1; i<=n; i++) {
        if (kordb[i]) {
            kor.push_back(i);
            cnt*=(kordb[i]+1);
        }
    }
    for (int i=0; i<cnt; i++) {
        vector<int> a=konv(i);
        for (int k=0; k<kor.size(); k++) {
            db[i]+=a[k]*kor[k];
        }
        for (int j=1; j<=i; j++) {
            vector<int> b=konv(j);
            long long ert=1;
            bool jo=1;
            for (int k=0; k<kor.size(); k++) {
                ert*=alatt(a[k], b[k]), ert%=mod;
                if (b[k]>a[k]) {
                    jo=0;
                }
            }

            if (jo) {
                sz[i].push_back({j, ert});
            }
        }
    }
    dp[cnt-1][0]=1;
    for (int i=cnt-1; i>=0; i--) {
        for (int j=0; j<=n; j++) {
            if (!dp[i][j]) {
                continue;
            }
            for (auto k:sz[i]) {
                int mask=k.first, s=db[mask];
                long long ert=k.second;
                dp[i-mask][s]+=dp[i][j]*ert%mod*solve(mask, db[i], j)%mod;
                dp[i-mask][s]%=mod;
            }
        }
    }
    for (int i=0; i<=n; i++) {
        sum+=dp[0][i];
        sum%=mod;
    }
    cout << sum << "\n";
    return 0;
}