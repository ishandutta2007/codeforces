#include<bits/stdc++.h>
#define int long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
struct node{
	int l,r,mx,sum;
};
int n,a[1<<18];
V<node> get(int l,int r){
	V<node> re;
	if(l==r){
		re.PB((node){
			max(0ll,a[l]),max(0ll,a[l]),max(0ll,a[l]),a[l]
		});
		RE re;
	}
	int mid=(l+r)>>1;
	V<node> vl=get(l,mid),vr=get(mid+1,r);
	rep(i,0,(r-l+1)/2){
		re.PB((node){
			max(vl[i].l,vl[i].sum+vr[i].l),max(vr[i].r,vr[i].sum+vl[i].r),
			max({vl[i].mx,vr[i].mx,vl[i].r+vr[i].l}),vl[i].sum+vr[i].sum
		});
	}
	swap(vl,vr);
	rep(i,0,(r-l+1)/2){
		re.PB((node){
			max(vl[i].l,vl[i].sum+vr[i].l),max(vr[i].r,vr[i].sum+vl[i].r),
			max({vl[i].mx,vr[i].mx,vl[i].r+vr[i].l}),vl[i].sum+vr[i].sum
		});
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	rep(i,0,1<<n)cin>>a[i];
	V<node> v=get(0,(1<<n)-1);
	int now=0,q;
	cin>>q;
	FOR(i,1,q){
		int x;
		cin>>x;
		now^=(1<<x);
		cout<<v[now].mx<<'\n';
	}
	RE 0;
}