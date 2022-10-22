/*

DP





ll int
 dp 










*/
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
using namespace std;
int ch[20000005][2],val[20000005],tag[20000005],cnt;
int a[100005],mini[100005][20],log_2[100005];
int n,k;
int get(int l,int r){
	if(l>r)RE 1e9;
	int len=(r-l+1);
	RE min(mini[l][log_2[len]],mini[r-(1<<log_2[len])+1][log_2[len]]);
}
void init(int x,int tl,int tr){
	if(tr-tl+1>=n){
		val[x]=get(1,n);
	}else{
		int l=(tl-1)%n+1,r=(tr-1)%n+1;
		if(l<=r){
			val[x]=get(l,r);
		}else val[x]=min(get(l,n),get(1,r));
	}
}
void pushdown(int x,int tl,int tr){
	if(tl==tr){
		tag[x]=0;RE;
	}
	if(!ch[x][0])ch[x][0]=++cnt;
	if(!ch[x][1])ch[x][1]=++cnt;
	if(tag[x]){
		tag[x]=0;
		FOR(i,0,1){
			val[ch[x][i]]=val[x];
			tag[ch[x][i]]=1;
		}
	}else if(!val[ch[x][0]]){
		int mid=(tl+tr)>>1;
		init(ch[x][0],tl,mid);
		init(ch[x][1],mid+1,tr); 
	}
}
void update(int x,int tl,int tr,int l,int r,int num){
	if(l>tr||tl>r)RE;
	if(tl>=l&&tr<=r){
		val[x]=num;
		tag[x]=1;RE;
	}
	pushdown(x,tl,tr);
	int mid=(tl+tr)>>1;
	update(ch[x][0],tl,mid,l,r,num);
	update(ch[x][1],mid+1,tr,l,r,num);
	val[x]=min(val[ch[x][0]],val[ch[x][1]]);
}
int query(int x,int tl,int tr,int l,int r){
	if(l>tr||tl>r)RE 1e9;
	if(tl>=l&&tr<=r){
		RE val[x];
	}
	pushdown(x,tl,tr);
	int mid=(tl+tr)>>1;
	RE min(query(ch[x][0],tl,mid,l,r),query(ch[x][1],mid+1,tr,l,r));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	FOR(i,2,n)log_2[i]=log_2[i/2]+1;
	FOR(i,1,n)mini[i][0]=a[i];
	FOR(i,1,18){
		FOR(j,1,n)if(j+(1<<i)<=n+1){
			mini[j][i]=min(mini[j][i-1],mini[j+(1<<(i-1))][i-1]);
		}
	}
	int q;
	cin>>q;
	int x,y,z;
	int tp,root=1;cnt=1;
	val[1]=get(1,n);
	FOR(i,1,q){
		cin>>tp;
		if(tp==1){
			cin>>x>>y>>z;
			update(root,1,n*k,x,y,z);
		}else{
			cin>>x>>y;
			cout<<query(root,1,n*k,x,y)<<'\n';
		}
	}
	RE 0;
}