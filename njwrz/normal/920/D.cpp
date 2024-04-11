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
int n,k,v;
int a[5005],ta[5005];
int dp[5005][5005],lst[5005][5005];
bool vis[5005];
V<P<int,P<int,int> > > ansv;
void solve1(int x,int y){
	int t=(a[x]+k-1)/k;
	ansv.PB(MP(t,MP(x,y)));
	a[y]+=a[x];a[x]=0;
}
void solve2(int x,int y){
	int t=a[x]/k;
	ansv.PB(MP(t,MP(x,y)));
	a[y]+=t*k;
	a[x]-=t*k;
}
void solve3(int x,int y,int t){
	ansv.PB(MP(t,MP(x,y)));
	a[y]+=t*k;
	a[x]-=t*k; 
}
void print(){
	for(auto u:ansv){
		if(u.F)cout<<u.F<<' '<<u.S.F<<' '<<u.S.S<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>v;
	int tv=v%k;
	FOR(i,1,n)cin>>a[i],ta[i]=a[i]%k;
	dp[0][0]=1;
	rep(j,1,k)dp[0][j]=-1e9;
	FOR(i,1,n){
		rep(j,0,k)if(dp[i-1][j]>0){
			int to=(j+ta[i])%k;
			if(dp[i][to]==0||dp[i][to]<dp[i-1][j]+(j+ta[i]>=k)){
				dp[i][to]=dp[i-1][j]+(j+ta[i]>=k);
				lst[i][to]=j;
			}
			if(dp[i][j]==0||dp[i][j]<dp[i-1][j]){
				dp[i][j]=dp[i-1][j];
				lst[i][j]=j;
			}
		}
//		rep(j,0,k)cout<<dp[i][j]<<' ';
//		cout<<'\n'; 
	}
	if(dp[n][tv]){
		int nowx=n;
		while(nowx){
			if(lst[nowx][tv]==tv){
				nowx--;
			}else {
				vis[nowx]=1;tv=(tv-ta[nowx]+k)%k;
				nowx--;
			}
		}
		int st=0;
		FOR(i,1,n)if(vis[i]){
			st=i;break;
		}
		if(st==0){
			st=1;
			solve1(1,2);
		}
		int lst=0;
		for(int i=n;i>=1;i--){
			if(vis[i]){
				if(lst){
					solve1(lst,i);
				}
				lst=i;
			}
		}
		lst=0;
		FOR(i,1,n)if(!vis[i]){
			if(lst)solve1(lst,i);
			lst=i;
		}
		solve2(lst,st);
		if(a[st]<v){
			cout<<"NO";
		}else{
			cout<<"YES\n";
			if(a[st]>v)FOR(i,1,n)if(i!=st){
				solve3(st,i,(a[st]-v)/k);
				break;
			}
			print();
			assert(a[st]==v);
		}
	}else{
		cout<<"NO";
	}
	RE 0;
}