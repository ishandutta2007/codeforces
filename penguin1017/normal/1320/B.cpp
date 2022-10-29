#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
vi g[N];
int a[N],vis[N],d[N];
queue<int> q;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[v].pb(u);
	}
	int k;
	scanf("%d",&k);
	per(i,0,k)scanf("%d",&a[i]);
	rep(i,0,N)d[i]=N;
	q.push(a[0]),vis[a[0]]=1,d[a[0]]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(vis[v]){
				if(d[u]+1==d[v])vis[v]=2;
			}
			else{
				d[v]=d[u]+1;
				vis[v]=1;
				q.push(v); 
			}
		}
	}
	int ans=0;
	rep(i,1,k){
		if(d[a[i]]<d[a[i-1]]+1)++ans;
	} 
	printf("%d ",ans);
	ans=0;
	rep(i,1,k){
		if(d[a[i]]<d[a[i-1]]+1)++ans;
		else if(vis[a[i]]>1)++ans;
	}
	printf("%d",ans);
}
/*
5 5
1 2
2 3
2 4
3 5
4 5
4
1 2 3 5
*/