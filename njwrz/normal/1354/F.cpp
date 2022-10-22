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
using namespace std;
struct node{
	int id,add,val;
};
node p[100];
int n,dp[100][100];
bool f[100];
bool cmp(node x,node y){
	RE x.add<y.add;
}
deque<int> ans;
void print(int x,int y){
	if(!y)RE;
	if(x&&dp[x][y]==dp[x-1][y-1]+(x-1)*p[y].add+p[y].val){
		ans.PF(y);
		print(x-1,y-1);
	}else{
		f[y]=1;
		print(x,y-1);
	}
}
void solve(){
	int k;
	cin>>n>>k;
	FOR(i,1,n)cin>>p[i].val>>p[i].add,p[i].id=i;
	FILL(dp,0);
	sort(p+1,p+n+1,cmp);
	FOR(i,1,k){
		FOR(j,0,n)dp[i][j]=-1e17;
	}
	dp[0][0]=0;
	FOR(i,1,n)dp[0][i]=dp[0][i-1]+(k-1)*p[i].add; 
	FOR(i,1,k){
		FOR(j,i,n){
			dp[i][j]=max(dp[i-1][j-1]+(i-1)*p[j].add+p[j].val,dp[i][j-1]+(k-1)*p[j].add);
//			cout<<dp[i][j]<<" ";
		}
//		cout<<'\n';
	}
	ans.clear();FILL(f,0);
	print(k,n);
	cout<<n*2-k<<'\n';
	int t=ans.back();ans.pop_back();
	for(auto u:ans)cout<<p[u].id<<' ';
	FOR(i,1,n){
		if(f[i]){
			cout<<p[i].id<<' '<<-p[i].id<<' ';
		}
	}
	cout<<p[t].id<<' ';
	cout<<'\n';
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}