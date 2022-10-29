#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=1005;
const ll mod=998244353;
const ll Inf=1e18;
vi g[7][N],e;
int x[7],y[7],X[N],Y[N];
bool check(int i,int j,int k){
	if(j==k)return 0;
	if(X[k]<min(x[i],X[j])||X[k]>max(x[i],X[j]))return 0;
	if(Y[k]<min(y[i],Y[j])||Y[k]>max(y[i],Y[j]))return 0;
	return 1ll*(X[k]-x[i])*(Y[k]-Y[j])==1ll*(X[k]-X[j])*(Y[k]-y[i]);
}
int p[7],v[N];
int k,n,t;
bool dfs(int i){
	if(t==k)return 0;
	for(auto x:g[p[t]][i]){
	//	cout<<p[t]<<' '<<x<<' '<<i<<"check\n";
		if(!v[x]){
			++t;
			if(!dfs(x))return 0;
		}
	}
	return e.pb(i),v[i]=1,1;
}
int main(){
	//pre();
	scanf("%d%d",&k,&n);
	rep(i,0,k)scanf("%d%d",&x[i],&y[i]);
	rep(i,0,n)scanf("%d%d",&X[i],&Y[i]);
	rep(i,0,k)rep(j,0,n)rep(o,0,n){
		if(check(i,j,o))g[i][j].pb(o);
		if(g[i][j].size()==k)break;
	}
	int ans=0;
	rep(i,0,n){
		rep(j,0,k)p[j]=j;
		do{
		//	rep(j,0,k)cout<<p[j]<<' ';
		//	cout<<"P\n";
			t=0;
			while(e.size())v[e.back()]=0,e.pop_back();
			if(dfs(i)){
				++ans;
				break;
			}
		}while(next_permutation(p,p+k));
	}
	cout<<ans; 
}