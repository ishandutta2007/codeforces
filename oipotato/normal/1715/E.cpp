#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const LL is_query = -(1LL<<62);
struct Line {
    LL m, b;  mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ(); if (!s) return 0;
    LL x=rhs.m; return b-s->b<(__int128)(s->m-m)*x;
    }
};
struct HuLLDynamic : public multiset<Line> { // wiLL maintain upper huLL for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y==begin()){ if(z==end())return 0; return y->m==z->m&&y->b<=z->b; }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (__int128)(x->b - y->b)*(z->m - y->m) >= (__int128)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(LL m, LL b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    LL eval(LL x) { auto l=*lower_bound((Line){x,is_query}); return l.m*x+l.b; }
}Convex;
const int N=100010;
bool vis[N];
LL d[N];
int n,m,k;
vector<pair<int,int>>g[N];
priority_queue<pair<LL,int>,vector<pair<LL,int>>,greater<pair<LL,int>>>q;
void dij()
{
	rep(i,n)vis[i]=0,q.push(mp(d[i],i));
	for(;!q.empty();)
	{
		auto u=q.top();q.pop();
		if(vis[u.second])continue;
		vis[u.second]=1;
		for(auto [x,y]:g[u.second])
		if(u.first+y<d[x])
		{
			d[x]=u.first+y;
			q.push(mp(d[x],x));
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,m){int u,v,w;scanf("%d%d%d",&u,&v,&w);g[u].pb(mp(v,w));g[v].pb(mp(u,w));}
	rep(i,n)d[i]=(LL)1e18;
	d[1]=0;
	dij();
	rep(tim,k)
	{
		Convex.clear();
		rep(i,n)Convex.insert_line(2LL*i,-(d[i]+(LL)i*i));
		rep(i,n)d[i]=min(d[i],-Convex.eval(i)+(LL)i*i);
		dij();
	}
	rep(i,n)printf("%lld%c",d[i]," \n"[i==n]);
    return 0;
}