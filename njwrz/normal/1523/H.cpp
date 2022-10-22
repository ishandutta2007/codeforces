#include<iostream>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RE return
#define MP make_pair
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
int n,q;
int a[20005];
int dp[20005][35][15];
P<int,int> mx[1<<16];
void build(int x,int l,int r){
	if(l==r){
		mx[x]=MP(l+a[l],l);RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	mx[x]=max(mx[lc],mx[rc]);
}
P<int,int> get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr)RE mx[x];
	if(l>tr||tl>r)RE MP(0,0);
	int mid=(l+r)>>1;
	RE max(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
int f[30],to[30];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	FOR(i,1,n)cin>>a[i];
	build(1,1,n);
	FOR(i,1,n){
		if(i+a[i]>=n){
			FOR(j,0,30)dp[i][j][0]=i;
			continue;
		}
		FOR(j,0,30){
			if(i+a[i]+j>n)dp[i][j][0]=dp[i][j-1][0];
			else{
				P<int,int> now=get(1,1,n,i,i+a[i]+j);
				dp[i][j][0]=now.S;
			}
		}
	}
	for(int i=n;i>=1;i--){
		FOR(j,1,14){
			FOR(k,0,30)dp[i][k][j]=0;
			FOR(k,0,30)FOR(t,0,k){
				int now=dp[dp[i][t][j-1]][k-t][j-1];
				if(now+a[now]>dp[i][k][j]+a[dp[i][k][j]])dp[i][k][j]=now;
			}
		}
	}
	FOR(_,1,q){
		int l,r,k;
		cin>>l>>r>>k;
		if(l==r){
			cout<<0<<'\n';continue;
		}
		if(a[l]+l+k>=r){
			cout<<1<<'\n';continue;
		}
		int ans=0;
		FOR(i,0,k)f[i]=l;
		for(int i=14;i>=0;i--){
			FOR(j,0,k)to[j]=0;
			FOR(j,0,k)FOR(t,0,j){
				int now=dp[f[t]][j-t][i];
				if(now+a[now]>a[to[j]]+to[j])to[j]=now;
			}
			bool ff=0;
			FOR(j,0,k)if(to[j]+a[to[j]]+k-j>=r)ff=1;
			if(ff)continue;
			FOR(j,0,k)f[j]=to[j];
			ans+=1<<i;
		}
		cout<<ans+2<<'\n';
	}
	RE 0;
}