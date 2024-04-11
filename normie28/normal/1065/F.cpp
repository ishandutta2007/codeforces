#include "bits/stdc++.h"
#define MAXN 1000009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;
 
typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
vector<int>adj[MAXN],v;
int in[MAXN],out[MAXN],lvl[MAXN],TIM;
int dp[MAXN],n,k,lift[MAXN],P[MAXN][20];
void pre(int nd){
	in[nd]=++TIM;
	if(adj[nd].size()==0)
		v.pb(nd);
	for(int j=1;j<=19;j++)
		if(~P[nd][j-1])
			P[nd][j]=P[P[nd][j-1]][j-1];	
	for(int i=0;i<int(adj[nd].size());i++){
		int to=adj[nd][i];
		lvl[to]=lvl[nd]+1;	
		P[to][0]=nd;
		pre(to);		
	}
	out[nd]=TIM;
}
void dfs(int nd){
	int ms=0;
	for(int i=0;i<int(adj[nd].size());i++){
		int to=adj[nd][i];
		dfs(to);
		umax(ms,dp[to]);
	}
	dp[nd]+=ms;
}
bool cmp(int x,int y){
	return (lvl[x]<lvl[y]);
}
int jump(int x,int y){
	for(int j=19;j>=0;j--)
		if(~P[x][j] and lvl[x]-(1<<j)>=y)
			x=P[x][j];
	return x;		
}
int s[MAXN<<2];
void upd(int p,int v,int nd,int x,int y){
	if(x==y){
		s[nd]=v;
		return;
	}
	int mid=(x+y)>>1;
	if(p<=mid)
		upd(p,v,nd<<1,x,mid);
	else
		upd(p,v,nd<<1|1,mid+1,y);
	s[nd]=min(s[nd<<1],s[nd<<1|1]);		
}
int tap(int l,int r,int nd,int x,int y){
	if(l>y or x>r)
		return INF;
	if(l<=x and y<=r)
		return s[nd];
	int mid=(x+y)>>1;
	return min(tap(l,r,nd<<1,x,mid),tap(l,r,nd<<1|1,mid+1,y));			
}
int main(){
	memset(P,-1,sizeof P);
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++){
    	int p;
		scanf("%d",&p);
		adj[p].pb(i);	
    }
	pre(1);
	sort(all(v),cmp);
	for(int i=1;i<=4*n;i++)
		s[i]=INF;
	for(int i=0;i<int(v.size());i++){
		int nd=v[i];
		if(lvl[nd]-k<0)
			lift[nd]=0;
		else{	
			int dad=jump(nd,lvl[nd]-k);
			lift[nd]=min(lvl[nd]-k,tap(in[dad],out[dad],1,1,n));
		}
		upd(in[nd],lift[nd],1,1,n);
	}
	tr(it,v)
		dp[jump(*it,lift[*it])]++;
	dfs(1);
	cout<<dp[1];
}