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
int n[4],a[600005],dp[600005],mini[1<<21];
V<int> v[600005];
void build(int x,int l,int r){
	if(l==r){
		if(l<n[0]){
			mini[x]=0;
		}else mini[x]=1e9;
		RE;
	}
	mini[x]=1e9;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)|1,mid+1,r);
}
int get(int x,int l,int r,int it){
	if(l!=r){
		gmin(mini[x<<1],mini[x]);
		gmin(mini[(x<<1)|1],mini[x]);
	}
	if(l==r){
		RE mini[x];
	}
	int mid=(l+r)>>1;
	if(it<=mid){
		RE get(x<<1,l,mid,it);
	}else RE get((x<<1)|1,mid+1,r,it);
}
void update(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr){
		gmin(mini[x],val);RE;
	}
	if(l>tr||tl>r)RE ;
	if(l!=r){
		gmin(mini[x<<1],mini[x]);
		gmin(mini[(x<<1)|1],mini[x]);
	}
	int mid=(l+r)>>1;
	update(x<<1,l,mid,tl,tr,val);
	update((x<<1)|1,mid+1,r,tl,tr,val);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	rep(i,0,4)cin>>n[i];
	int now=0;
	FOR(i,0,3){
		rep(j,0,n[i]){
			cin>>a[j+now];
		}
		now+=n[i];
	}
	int t;
	int x,y;
	cin>>t;
	FOR(i,1,t){
		cin>>x>>y;
		x--;y--;
		v[x].PB(y+n[0]);
	}
	cin>>t;
	FOR(i,1,t){
		cin>>x>>y;
		x--;y--;
		v[x+n[0]].PB(y+n[0]+n[1]);
	}
	cin>>t;
	FOR(i,1,t){
		cin>>x>>y;
		x--;y--;
		v[x+n[0]+n[1]].PB(y+n[0]+n[1]+n[2]);
	}
	int sum[5];
	sum[0]=0;
	FOR(i,1,4){
		sum[i]=sum[i-1]+n[i-1];
	}
	int ans=1e9;
	build(1,0,now-1);
	rep(i,0,now){
		dp[i]=get(1,0,now-1,i)+a[i];
		if(i>=sum[3]){
			gmin(ans,dp[i]);continue;
		}
		int lst=upb(sum+1,sum+5,i)-sum;
		int nxt=lst+1;
		lst=sum[lst];
		nxt=sum[nxt];
		sort(ALL(v[i]));
		for(auto u:v[i]){
			update(1,0,now-1,lst,u-1,dp[i]);
//			cout<<u<<' ';
			lst=u+1;
		}
		update(1,0,now-1,lst,nxt-1,dp[i]);
//		cout<<dp[i]<<'\n';
	}
	if(ans>=1e9){
		cout<<-1;
	}else cout<<ans;
	RE 0;
}