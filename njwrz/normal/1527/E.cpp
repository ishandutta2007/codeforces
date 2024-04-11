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
#define ll long long
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
int n,m;
int mini[1<<17],dp[35005],lst[35005],a[35005],add[1<<17];
void build(int x,int l,int r){
	add[x]=0;
	if(l==r){
		mini[x]=dp[l];RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	mini[x]=min(mini[lc],mini[rc]);
}
void pushdown(int x){
	add[lc]+=add[x];
	add[rc]+=add[x];
	mini[lc]+=add[x];
	mini[rc]+=add[x];
	add[x]=0; 
}
void update(int x,int l,int r,int tl,int tr,int num){
	if(l>=tl&&r<=tr){
		mini[x]+=num;add[x]+=num;
		RE;
	}
	if(l>tr||tl>r)RE ;
	pushdown(x);
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,num);
	update(rc,mid+1,r,tl,tr,num);
	mini[x]=min(mini[lc],mini[rc]);
}
int get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		RE mini[x];
	}
	if(l>tr||tl>r)RE 1e9;
	pushdown(x);
	int mid=(l+r)>>1;
	RE min(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
void solve(){
	cin>>n>>m;
	FOR(i,1,n){
		int x;
		cin>>x;a[i]=x;
		dp[i]=dp[i-1];
		if(lst[x])dp[i]+=i-lst[x];
		lst[x]=i;
	}
	rep(i,1,m){
		build(1,0,n);
		FILL(lst,0);
		FOR(j,1,n){
			if(lst[a[j]]){
//				cout<<get(1,0,n,0,lst[a[j]]-1)<<' ';
				update(1,0,n,0,lst[a[j]]-1,j-lst[a[j]]);
//				cout<<get(1,0,n,0,lst[a[j]]-1)<<'\n';
			}
			lst[a[j]]=j;
			dp[j]=get(1,0,n,0,j-1);
		}
//		cout<<'\n';
	}
	cout<<dp[n]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t=1;
	while(t--)solve();
	RE 0;
}