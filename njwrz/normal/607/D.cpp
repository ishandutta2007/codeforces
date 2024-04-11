//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
#define rc ((x<<1)|1) 
using namespace std;
V<int> v[200005];
int l[200005],r[200005],b[200005],t[200005],fa[200005],a[200005],cnt,mod=1e9+7,siz[200005];
void dfs(int x,int y){
	l[x]=++cnt;
	for(auto u:v[x])if(u!=y){
		dfs(u,x);
	}
	r[x]=cnt;
}
int tag[1<<19],val[1<<19],mul[1<<19];
void build(int x,int l,int r){
	tag[x]=1;
	mul[x]=1;
	if(l==r)RE;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void pushdown(int x,int l,int r){
	if(l!=r){
		tag[lc]=tag[lc]*tag[x]%mod;
		tag[rc]=tag[rc]*tag[x]%mod;
		mul[lc]=mul[lc]*tag[x]%mod;
		mul[rc]=mul[rc]*tag[x]%mod;
		val[lc]=val[lc]*tag[x]%mod;
		val[rc]=val[rc]*tag[x]%mod;
	}
	tag[x]=1;
}
void update(int x,int l,int r,int tl,int tr,int muti){
	pushdown(x,l,r);
	if(l>=tl&&r<=tr){
		tag[x]=tag[x]*muti%mod;
		mul[x]=mul[x]*muti%mod;
		val[x]=val[x]*muti%mod;
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,muti);
	update(rc,mid+1,r,tl,tr,muti);
	val[x]=(val[lc]+val[rc])%mod;
}
void update1(int x,int l,int r,int it,int add){
	pushdown(x,l,r);
	if(l==r){
		val[x]=(val[x]+add*mul[x])%mod;
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update1(lc,l,mid,it,add);
	else update1(rc,mid+1,r,it,add);
	val[x]=(val[lc]+val[rc])%mod;
}
int get(int x,int l,int r,int it){
	pushdown(x,l,r);
	if(l==r)RE mul[x];
	int mid=(l+r)>>1;
	if(mid>=it){
		RE get(lc,l,mid,it);
	}else RE get(rc,mid+1,r,it);
}
int getval(int x,int l,int r,int tl,int tr){
	pushdown(x,l,r);
	if(l>=tl&&r<=tr)RE val[x];
	if(l>tr||tl>r)RE 0;
	int mid=(l+r)>>1;
	RE (getval(lc,l,mid,tl,tr)+getval(rc,mid+1,r,tl,tr))%mod;
}
int __pow(int x,int y){
	if(!y)RE 1;
	int t=__pow(x,y/2);
	if(y&1){
		RE t*t%mod*x%mod;
	}else RE t*t%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	n=1;
	cin>>a[1]>>q;
	FOR(i,1,q){
		cin>>t[i];
		if(t[i]==1){
			int x,y;
			cin>>x>>y;
			fa[++n]=x;
			v[x].PB(n);
			a[n]=y;
		}else cin>>b[i];
	}
	dfs(1,-1);
	build(1,1,n);
	int tn=1;
	update1(1,1,n,1,a[1]);
	FOR(i,1,n)siz[i]=1;
	FOR(i,1,q){
		if(t[i]==1){
			tn++;
			update(1,1,n,l[fa[tn]],r[fa[tn]],__pow(siz[fa[tn]],mod-2)*(++siz[fa[tn]])%mod);
			update1(1,1,n,l[tn],a[tn]);
		}else{
			cout<<getval(1,1,n,l[b[i]],r[b[i]])*(b[i]==1?1:__pow(get(1,1,n,l[fa[b[i]]]),mod-2))%mod<<'\n';
		}
	}
	RE 0;
}