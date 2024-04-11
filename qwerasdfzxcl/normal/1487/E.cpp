#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll dp[200200][4], val[200200][4];
vector<pair<int, int>> adj[200200][4];
pair<ll, int> dtmp[200200];
int n[4], m[3];
bool chk[200200], vyes[200200];

int main(){
    for (int i=0;i<4;i++) scanf("%d", n+i);
    for (int i=0;i<4;i++){
        for (int j=0;j<n[i];j++){
            scanf("%lld", &val[j][i]);
            dp[j][i]=1e18;
        }
    }
    for (int i=0;i<3;i++){
        scanf("%d", m+i);
        for (int j=0;j<m[i];j++){
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            adj[a][i].push_back(make_pair(b, i+1));
            //adj[b][i+1].push_back(make_pair)
        }
    }
    for (int i=0;i<n[0];i++) dp[i][0]=val[i][0];
    for (int z=1;z<4;z++){
        vector<int> tmpv, cp;
        for (int i=0;i<n[z];i++){
            chk[i]=0;
            vyes[i]=1;
            tmpv.push_back(i);
        }
        for (int i=0;i<n[z-1];i++) dtmp[i]=make_pair(dp[i][z-1], i);
        sort(dtmp, dtmp+n[z-1]);
        for (int v=0;v<n[z-1];v++){
            for (auto &p:adj[dtmp[v].second][z-1]) if(vyes[p.first]) {
                cp.push_back(p.first);
                chk[p.first]=1;
            }
            for (int u:tmpv) if (!chk[u]){
                dp[u][z]=dtmp[v].first+val[u][z];
                //printf("%d %d = %lld = %lld + %lld\n", u, z, dp[u][z], dtmp[v].first, val[u][z]);
                vyes[u]=0;
            }
            tmpv.clear();
            for (int idx:cp){
                tmpv.push_back(idx);
                chk[idx]=0;
                vyes[idx]=1;
            }
            cp.clear();
        }
    }
    ll ans=1e18;
    for (int i=0;i<n[3];i++) ans=min(ans, dp[i][3]);
    if (ans==1e18) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}