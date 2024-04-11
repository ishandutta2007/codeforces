#include<cstdio>
#include<set>
#include<algorithm>
#include<cassert>
#include<climits>
using namespace std;
typedef long long ll;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
}h;
long long ans,f[1000010];
struct data
{
    int x,y;
    long long a;
    friend bool operator <(const data&a,const data&b){return a.x<b.x;}
}a[1000010];
#define rep(i,n) for(int i=1;i<=n;i++)
int n;
int main()
{
    scanf("%d",&n);
    rep(i,n)scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].a);
    sort(a+1,a+n+1);
    h.add(0ll,0ll);
    rep(i,n)
    {
        f[i]=h.query(a[i].y)+1ll*a[i].x*a[i].y-a[i].a;
        h.add(-1ll*a[i].x,f[i]);
        ans=max(ans,f[i]);
    }
    printf("%lld\n",ans);
    return 0;
}