#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define P pair<int, ll>
using namespace std;
const int maxn = 1e5 + 50;
const ll mod = 1e9 + 7;
int fa[maxn], nxt[maxn];
ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(a%b, b);
}
ll a[maxn], dep[maxn];
int n;
vector<int> g[maxn];
vector<P> s[maxn];
ll ans = 0;
void dfs(int u, int f){
    dep[u] = dep[f] + 1;
    fa[u] = f;
    if(u == 1){
        ans += a[u];
        ans %= mod;
        s[u].push_back(P(u, a[u]));
    }
    else{
        ll cur = a[u];
        int pre = u;
        int last = u;
        ll sum = 0;
        for(int i = 0; i < s[f].size(); ++i){
            ll t = gcd(cur, s[f][i].second);
            //cout<<"u:"<<u<<" t:"<<t<<endl;
            if(t != cur) {
                s[u].push_back(P(pre, cur));
                ans += cur*(dep[last]-dep[pre] + 1)%mod;
            }
            else ans += cur*(dep[last]-dep[pre] + 1)%mod;
            ans %= mod;
            cur = t; last = fa[pre]; pre = s[f][i].first;
        }
        s[u].push_back(P(pre, cur));
        ans += cur*(dep[last] - dep[pre] + 1)%mod;
        ans%=mod;
        //cout<<"ans:"<<ans<<endl;
    }
    for(int i = 0; i < g[u].size(); ++i){
        if(g[u][i] != f) dfs(g[u][i], u);
    }
}
int main()
{
	cin>>n;
	for(int i = 1; i <= n; ++i){
        scanf("%I64d", &a[i]);
	}
	for(int i = 1; i < n; ++i){
        int u, v; scanf("%d%d", &u, &v);
        g[u].push_back(v); g[v].push_back(u);
	}
	nxt[1] = 1;
	dfs(1, 0);
	ans %= mod; ans = (ans + mod)%mod;
	cout<<ans<<endl;
}
/*
5
4 5 6 0 8
1 2
1 3
1 4
4 5

*/