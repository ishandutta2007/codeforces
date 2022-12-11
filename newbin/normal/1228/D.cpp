#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 3e5 + 50;
int id[maxn];
vector<int> g[maxn];
int x[maxn], y[maxn];
unordered_map<ll, int> mp;
int n, m;
bool fnd(int u, int v){
    if(u > v) swap(u, v);
    ll t = (ll)u*maxn + v;
    if(mp.find(t) == mp.end()) return false;
    return true;
}
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= m; ++i){
        scanf("%d%d", &x[i], &y[i]);
        if(x[i] > y[i]) swap(x[i], y[i]);
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
        ll t = (ll)x[i]*maxn + y[i];
        mp[t] = 1;
	}
	int u  = x[1], v = y[1];
	id[u] = 1; id[v] = 2;
	int a1 = 1, a2 = 1;
	int ok = 1;
	for(int i = 0; i < g[u].size(); ++i){
        int t = g[u][i];
        if(t == v) continue;
        if(!fnd(t, v)) id[t] = 2, a2++;
	}
	for(int i = 0; i < g[v].size(); ++i){
        int t = g[v][i];
        if(t == u) continue;
        if(!fnd(t, u)) id[t] = 1, a1++;
	}

	ll sum = (ll)a1*(n-a1-a2) + (ll)a2*(n-a1-a2) + (ll)a1*a2;
	if(sum != m) ok = 0;
	if(a1 + a2 == n) ok = 0;
	for(int i = 1; i <= m; ++i){
        if(id[x[i]] == id[y[i]]){
            ok = 0; break;
        }
	}
	if(!ok){
        printf("-1\n");
	}
	else {
        for(int i = 1; i <= n; ++i){
            if(id[i]==0) id[i] = 3;
            if(i > 1) printf(" "); printf("%d", id[i]);
        }
	}
}