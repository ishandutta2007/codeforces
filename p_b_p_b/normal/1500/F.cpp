#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define drep(i,x,y) for (int i=(x);i>=(y);i--)
#define sz 1010101
typedef long long ll;
bool chkmax(ll &x,ll y){return x<y?x=y,1:0;}
bool chkmin(ll &x,ll y){return x>y?x=y,1:0;}

int n;
ll w[sz],d[sz];

void Out()
{
	static ll a[sz];
	a[1]=0,a[2]=d[2];
	rep(i,3,n) a[i]=a[i-1]+((d[i]+d[i-1]==w[i-1])==(a[i-1]>a[i-2])?1:-1)*d[i];
	ll mn=a[1]; rep(i,2,n) chkmin(mn,a[i]);
	rep(i,1,n) printf("%lld ",a[i]-mn);
}

void work(int l,ll L,ll R)
{
	if (l==n) return d[l]=L,void();
	auto in=[](ll x,ll l,ll r){return l<=x&&x<=r;};
	static ll ok[sz];
	set<ll>s;
	ll tp=1,dt=0; int r=-1;
	rep(i,l,n-1)
	{
		if (in(w[i],L,R)||s.count(tp*(w[i]-dt))) { r=i; break; }
		chkmax(L,0ll),chkmin(R,w[i]);
		auto it=s.begin();
		while (it!=s.end()&&!in((*it)*tp+dt,0,w[i])) s.erase(it++);
		it=s.end(); while (it!=s.begin()&&!in((*prev(it))*tp+dt,0,w[i])) s.erase(prev(it));
		if (L<=R) ok[i]=L; else ok[i]=*(s.begin())*tp+dt;
		if (L<=R) R=w[i]-R,L=w[i]-L,swap(L,R);
		tp*=-1,dt=w[i]-dt;
		if (L>R&&!s.size()) exit(puts("NO")&0);
		s.insert(tp*(w[i]-dt));
	}
	ll W;
	if (r!=-1) work(r+1,0,w[r]),W=w[r]; else r=n,W=(L<=R?L:*(s.begin())*tp+dt);
	drep(i,r,l) { d[i]=W; if (W==w[i-1]) W=ok[i-1]; else W=w[i-1]-W; }
} 

int main()
{
	cin>>n>>w[sz-1];
	rep(i,2,n-1) scanf("%lld",&w[i]);
	work(2,0,w[2]);
	puts("YES");
	Out();
	return 0;
}