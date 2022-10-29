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
const int N=1000+9;
const ll mod=998244353;
const ll Inf=1e18;
char s[N][N];
bool vis[N][N],ok[N][N]; 
int n,m;
int x[4]={0,1,-1,0};
int y[4]={1,0,0,-1};
void dfs(int i,int j){
	if(i<=0||i>n||j<=0||j>m||vis[i][j])return;
	vis[i][j]=1;
	if(s[i][j]=='.')return;
	rep(k,0,4)dfs(i+x[k],j+y[k]);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)scanf("%s",s[i]+1);
	int ans=0;
	rep(i,1,n+1){
		int op=0;
		char a='.';
		rep(j,1,m+1){
			if(s[i][j]!=a)a=s[i][j],op++;
		}
		if(op>2){
			cout<<-1;
			return 0;
		}
		if(op)rep(j,1,m+1)if(s[i][j]=='.')ok[i][j]^=1;
	}
	rep(j,1,m+1){
		int op=0;
		char a='.';
		rep(i,1,n+1){
			if(s[i][j]!=a)a=s[i][j],op++;
		}
		if(op>2){
			cout<<-1;
			return 0;
		}
		if(op)rep(i,1,n+1)if(s[i][j]=='.')ok[i][j]^=1;
	}
	rep(i,1,n+1){
		int op=1;
		rep(j,1,m+1)if(!ok[i][j])op=0;
		if(op){
			cout<<-1;
			return 0;
		} 
	}
	rep(j,1,m+1){
		int op=1;
		rep(i,1,n+1)if(!ok[i][j])op=0;
		if(op){
			cout<<-1;
			return 0;
		} 
	}
	rep(i,1,n+1){
		rep(j,1,m+1){
			if(!vis[i][j])dfs(i,j),ans+=s[i][j]=='#';
		}
	}
	printf("%d",ans); 
}