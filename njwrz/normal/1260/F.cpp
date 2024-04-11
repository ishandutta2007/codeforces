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
int n;
int l[100005],r[100005],mod=1e9+7,p[100005];
int __pow(int x,int y){
	if(!y)RE 1;
	int t=__pow(x,y/2);
	if(y&1){
		RE t*t%mod*x%mod;
	}else RE t*t%mod;
} 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
V<int> v[100005];
int in[100005],d[100005],siz[100005],L[100005],R[100005],top[100005],it[100005],sol[100005],cnts;
void dfs(int x,int y){
	siz[x]=1;
	for(auto u:v[x])if(u!=y){
		d[u]=d[x]+1;
		dfs(u,x);
		siz[x]+=siz[u];
	}
}
int cnt;
int to[100005];
void dfs2(int x,int y,int tp){
	L[x]=++cnt; it[cnt]=x;
	top[x]=tp;
	int maxi=0;
	for(auto u:v[x])if(u!=y){
		if(siz[u]>siz[maxi])maxi=u;
	}
	to[x]=maxi;
	if(maxi)sol[maxi]=sol[x],dfs2(maxi,x,tp);
	for(auto u:v[x])if(u!=y&&u!=maxi){
		++cnts;
		sol[u]=cnts;
		dfs2(u,x,u);
	}
	R[x]=cnt;
}
V<P<int,int> > q[100005];
void dfs3(int x,int y){
	q[sol[x]].PB(MP(L[x],x));
	for(auto u:v[x])if(u!=y)dfs3(u,x);
	for(auto u:v[x])if(u!=y&&u!=to[x]){
		for(auto ut:q[sol[u]]){
			q[sol[x]].PB(MP(L[x],ut.S));
		}
	}
}
int sum[1<<18],sum2[1<<18],tag[1<<18],tag2[1<<18];
V<int> re;
void pushdown(int x,int len1,int len2){
	add(sum2[lc],(sum[lc]*tag[x]+tag2[x]*len1)%mod);
	add(sum[lc],len1*tag[x]%mod);
	add(tag2[lc],(tag[lc]*tag[x]+tag2[x])%mod);
	add(tag[lc],tag[x]);
	add(sum2[rc],(sum[rc]*tag[x]+tag2[x]*len2)%mod);
	add(sum[rc],len2*tag[x]%mod);
	add(tag2[rc],(tag[rc]*tag[x]+tag2[x])%mod);
	add(tag[rc],tag[x]);
	tag[x]=0;tag2[x]=0;
}
void update(int x,int l,int r,int tl,int tr,int val){
	re.PB(x);
	if(l>=tl&&r<=tr){
		add(tag2[x],tag[x]*val%mod);
		add(tag[x],val);
		add(sum2[x],sum[x]*val%mod);
		add(sum[x],(r-l+1)*val%mod);
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	pushdown(x,mid-l+1,r-mid);
	update(lc,l,mid,tl,tr,val);
	update(rc,mid+1,r,tl,tr,val);
	sum[x]=(sum[lc]+sum[rc])%mod;
	sum2[x]=(sum2[lc]+sum2[rc])%mod;
}
void clear(){
//	FILL(sum,0);
//	FILL(sum2,0);FILL(tag,0);FILL(tag2,0);
	for(auto u:re)sum[u]=sum2[u]=tag[u]=tag2[u]=0;
	re.clear();
}
int s[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int muls=1;
	FOR(i,1,n){
		cin>>l[i]>>r[i];in[i]=r[i]-l[i]+1;
		muls=muls*(r[i]-l[i]+1)%mod;
	}
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	d[1]=1;
	dfs(1,-1);
	int ans=0;
	FOR(i,1,n){
		int t=muls*__pow(in[i],mod-2)%mod;
		add(p[l[i]],t);
		add(p[r[i]+1],mod-t);
	}
	FOR(i,1,1e5)add(p[i],p[i-1]),s[i]=(p[i]+s[i-1])%mod;
	FOR(i,1,n){
		int t=s[r[i]]-s[l[i]-1];
		t=(t-muls+mod)%mod;
		add(ans,t*__pow(in[i],mod-2)%mod*d[i]%mod);
	}
//	cout<<ans<<'\n';
	sol[1]=1;
	cnts=1;
	dfs2(1,-1,1);
	dfs3(1,-1);
	FOR(i,1,n){
		if(q[i].empty())continue;
		sort(ALL(q[i]),greater<P<int,int> >());
		int tl=q[i].back().F,tr=q[i].front().F;
		int iter=0;
		for(int j=tr;j>=tl;j--){
			while(iter<q[i].size()&&q[i][iter].F>=j){
				update(1,1,1e5,l[q[i][iter].S],r[q[i][iter].S],__pow(in[q[i][iter].S],mod-2));
				iter++;
			}
			ans=(ans-sum2[1]*2*muls%mod+mod)%mod;
		}
		clear();
	}
	cout<<ans;
	RE 0;
}