#include <bits/stdc++.h>

using namespace std;
const int c=305;
long long dps[c][c], dpk[c][c], ss[c], kk[c], ans, ossz=1, mod=998244353, o2=499122177;
int n, k;
vector<int> sz[c];
bool v[c];
void solve(int a, int b) {
    for (int i=0; i<=n; i++) {
        ss[i]=0, kk[i]=0;
    }
    long long koms=0, komk=0;
    for (int i=0; i<=k; i++) {
        ss[i]+=(dps[a][i]*(koms+komk+dps[b][i])%mod);
        kk[i]+=(dpk[a][i]*(koms+komk+dps[b][i])%mod);
        ss[i]%=mod, kk[i]%=mod;
        koms+=dps[b][i], komk+=dpk[b][i];
        koms%=mod, komk%=mod;
    }
    koms=0, komk=0;
    for (int i=0; i<=k; i++) {
        ss[i]+=(dps[b][i+1]*(koms+komk+dps[a][i]+dpk[a][i])%mod);
        if (i) kk[i]+=(dpk[b][i-1]*(koms+komk));
        ss[i]%=mod, kk[i]%=mod;
        koms+=dps[a][i], komk+=dpk[a][i];
        koms%=mod, komk%=mod;
    }
    for (int i=0; i<=k; i++) {
        dps[a][i]=ss[i]%mod;
        dpk[a][i]=kk[i]%mod;
    }
}
void dfs(int a) {
    v[a]=true;
    dpk[a][0]=1;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            solve(a, x);
        }
    }
    for (int i=0; i<k; i++) {
        dps[a][k]+=dps[a][i]+dpk[a][i];
    }
    dps[a][k]+=dpk[a][k];
    dps[a][k]%=mod;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        ossz*=2;
        ossz%=mod;
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                dps[i][j]=dpk[i][j]=0;
            }
            v[i]=0;
        }
        dfs(1);
        long long rdb=0;
        for (int i=0; i<=k; i++) {
            rdb+=dps[1][i];
        }
        ans+=ossz-rdb%mod+mod;
    }
    ans=(ans-1)%mod;
    for (int i=1; i<=n; i++) {
        ans*=o2;
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}