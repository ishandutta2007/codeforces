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
const int N=1e3+9;
const ll mod=998244353;
pii pos[N][N];
queue<pii> q;
int vis[N][N],flag,dis[4][2]={0,1,0,-1,1,0,-1,0};
char ans[N][N],s[4]={'L','R','U','D'},s2[4]={'R','L','D','U'};
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)rep(j,1,n+1){
		scanf("%d%d",&pos[i][j].fi,&pos[i][j].se);
		if(i==pos[i][j].fi&&j==pos[i][j].se)q.push({i,j}),ans[i][j]='X',vis[i][j]=1;
	}
	while(!q.empty()){
		pii p=q.front();
		q.pop();
		int x=p.fi,y=p.se;
	//	cout<<x<<' '<<y<<"xy\n";
		rep(i,0,4){
			int a=x+dis[i][0],b=y+dis[i][1];
			if(!a||!b||a>n||b>n)continue;
			if(vis[a][b])continue;
		//	cout<<a<<' '<<b<<"ab\n";
			if(pos[a][b].fi==pos[x][y].fi&&pos[a][b].se==pos[x][y].se)ans[a][b]=s[i],q.push({a,b}),vis[a][b]=1;
		}
	}
	rep(i,1,n+1)rep(j,1,n+1){
		if(!vis[i][j]&&pos[i][j].fi!=-1){
		//	cout<<i<<' '<<j<<"check\n";
			printf("INVALID\n");
			return 0;
		}
	}
	rep(x,1,n+1)rep(y,1,n+1){
		if(!vis[x][y]){
			rep(i,0,4){
				int a=x+dis[i][0],b=y+dis[i][1];
				if(!a||!b||a>n||b>n)continue;
				if(vis[a][b]==1)continue;
				ans[x][y]=s2[i];
				break;
			}
			if(!ans[x][y]){
				printf("INVALID\n");
				return 0;
			}
		}
	}
	printf("VALID\n");
	rep(i,1,n+1){
		printf("%s\n",ans[i]+1);
	}
}