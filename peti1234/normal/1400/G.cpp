#include <bits/stdc++.h>

using namespace std;
const int c=22, k=300002, mod=998244353;
long long ans, fakt[k], inv[k], ks[c];
int n, m, cnt, ki[k], csop[k], mask[c], osszdb[c][c], kuldb;
vector<int> komp[c], sz[k], valt[k];
bool jo[c][1<<20];
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
long long alatt(int a, int b) {
    if (a<b || b<0) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
void dfs(int a) {
    komp[cnt].push_back(a);
    csop[a]=cnt;
    for (int x:sz[a]) {
        if (!csop[x]) {
            dfs(x);
        }
    }
}
int lsb(int a) {
    return (a & (-a));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    fakt[0]=inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        valt[a].push_back(i);
        valt[b+1].push_back(-i);
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (sz[i].size()>0 && !csop[i]) {
            cnt++;
            dfs(i);
            int si=komp[cnt].size();
            for (int i=0; i<si; i++) {
                ki[komp[cnt][i]]=i;
            }
            jo[cnt][0]=1;
            for (int i=1; i<(1<<si); i++) {
                int k=lsb(i), l=__builtin_ctz(k), ert=komp[cnt][l];
                bool ans=1;
                if (!jo[cnt][i-k]) {
                    ans=0;
                }
                for (int cs:komp[cnt]) {
                    for (int j:sz[ert]) {
                        if (cs==j && (i&(1<<ki[cs]))) {
                            ans=0;
                        }
                    }
                }
                jo[cnt][i]=ans;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        bool spec=0;
        for (int j:valt[i]) {
            int ert=abs(j);
            if (csop[ert]) {
                spec=1;
                mask[csop[ert]]^=(1<<ki[ert]);
            } else {
                if (j>0) {
                    kuldb++;
                } else {
                    kuldb--;
                }
            }
        }
        ks[0]=1;
        if (spec) {
            for (int i=1; i<=m; i++) {
                ks[i]=0;
            }
            for (int i=1; i<=cnt; i++) {
                for (int j=0; j<=m; j++) {
                    osszdb[i][j]=0;
                }
                osszdb[i][0]=1;
                for (int sub=mask[i]; sub>0; sub=((sub-1)&mask[i])) {
                    if (jo[i][sub]) {
                        osszdb[i][__builtin_popcount(sub)]++;
                    }
                }
                for (int j=m; j>=0; j--) {
                    for (int k=m; k>=1; k--) {
                        if (ks[j] && osszdb[i][k]) {
                            ks[j+k]+=ks[j]*osszdb[i][k];
                            ks[j+k]%=mod;
                        }
                    }
                }
            }
        }
        for (int j=0; j<=m; j++) {
            ans+=ks[j]*alatt(kuldb, i-j);
            ans%=mod;
        }
    }
    cout << ans << "\n";
    return 0;
}