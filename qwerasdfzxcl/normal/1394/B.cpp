#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll myhash1[200200], myhash2[200200], myhash3[200200];
vector<pair<int, int>> adj[200200];
int deg[200200];
__int128_t sum1[10][10], sum2[10][10], sum3[10][10], S1 = 0, S2 = 0, S3 = 0;
vector<int> cur;

void make_hash(int n, ll* a){
    for (int i=1;i<=n;i++){
        for (int j=0;j<63;j++) if (rand()&1) a[i] |= (1<<j);
    }
}

bool nxt(int n){
    bool ret = 0;
    for (int i=1;i<=n;i++) if (cur[i]!=i) ret = 1;
    if (!ret) return 0;
    //printf("YES\n");
    for (int i=n;i>=1;i--){
        //printf("%d ", i);
        cur[i]++;
        if (cur[i]<=i) break;
        cur[i] = 1;
    }
    //printf("\n");
    return ret;
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    make_hash(n, myhash1);
    make_hash(n, myhash2);
    make_hash(n, myhash3);
    for (int i=0;i<m;i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        adj[x].emplace_back(z, y);
        deg[x]++;
    }
    for (int i=1;i<=n;i++) sort(adj[i].begin(), adj[i].end());
    for (int i=1;i<=n;i++){
        assert(deg[i]==(int)adj[i].size());
        S1 += myhash1[i];
        S2 += myhash2[i];
        S3 += myhash3[i];
        for (int j=0;j<deg[i];j++){
            sum1[deg[i]][j+1] += myhash1[adj[i][j].second];
            sum2[deg[i]][j+1] += myhash2[adj[i][j].second];
            sum3[deg[i]][j+1] += myhash3[adj[i][j].second];
        }
    }
    cur.resize(k+1);
    for (int i=1;i<=k;i++) cur[i] = 1;
    ll ans = 0;
    while(true){
        //printf("%d\n", cur[1]);
        __int128_t tmp1 = 0, tmp2 = 0, tmp3 = 0;
        for (int i=1;i<=k;i++){
            tmp1 += sum1[i][cur[i]];
            tmp2 += sum2[i][cur[i]];
            tmp3 += sum3[i][cur[i]];
        }
        if (tmp1==S1 && tmp2==S2 && tmp3==S3) ans++;
        if (!nxt(k)) break;
    }
    printf("%lld\n", ans);
    return 0;
}