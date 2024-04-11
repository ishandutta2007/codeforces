#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD=1000000007;

int N, M, K;
int G[1000010];
int sums[1000010];
int cnt[10];

LL powMod(LL x, LL y, LL mod) {
    if (y<1) return 1;
    if (y%2) return x*powMod(x, y-1, mod)%mod;
    return powMod(x*x%mod, y/2, mod);
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    memset(G, -1, sizeof G);
    
    for (int i=0; i<M; i++) {
	int u, v; scanf("%d%d", &u, &v); u--; v--;
	if (u+1==v) continue;
	if (u+K+1!=v || G[u]!=-1) { puts("0"); return 0; }
	G[u] = v;

    }

    int x=-1, y=-1;
    for (int i=0; i<N; i++) {
	if (x==-1 && G[i]!=-1) x=G[i];
	if (G[i]!=-1) y=i;
    }
    if (y!=-1 && x!=-1 && x<=y)  { puts("0"); return 0; }

    for (int i=0; i<=N; i++) {
	if (G[i]==-1) sums[i+1]++;
	sums[i+1] = (sums[i+1]+sums[i])%MOD;
    }
    
    LL ans=1;
    for (int i=0; i<N-K-1; i++) {
	if (i+K+1<=y) continue;
	if (x!=-1 && x<=i) break;
	if (G[i]!=-1) continue;
	
	int t=min(N-K-2, i+K);
	if (x!=-1) t = min(t, x-1);
	//printf("%d %d\n", i, t);
	ans = (ans + powMod(2, sums[t+1]-sums[i+1], MOD))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}