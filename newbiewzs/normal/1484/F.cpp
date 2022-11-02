#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
#define int long long
using namespace std;
typedef long long ll;
const int N=605;
int n,m,qq,x,y,z;
int f[N][N],vis[N],da[N*N];
vector<pii > q[N];
pair<int, pii > g[N*N];
signed main(){
	ci;
	cin>>n>>m;
	memset(f,10,sizeof(f));
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		f[x][y]=f[y][x]=min(f[x][y],z);
		g[i]=mp(x,mp(y,z));
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				if(f[k][j]>f[k][i]+f[i][j]){
					f[k][j]=f[k][i]+f[i][j];
				}
			}
		}
	}
	cin>>qq;
	for(int i=1;i<=qq;i++){
		cin>>x>>y>>z;
		q[x].pb(mp(y,z));
		q[y].pb(mp(x,z));
	}
	for(int i=1;i<=n;i++){
		memset(vis,-10,sizeof(vis));
		for(int k=0;k<q[i].size();k++){
			for(int j=1;j<=n;j++){
				vis[j]=max(vis[j],q[i][k].se-f[j][q[i][k].fi]);
			}
		}
		for(int k=1;k<=m;k++){
			if(f[i][g[k].fi]+g[k].se.se<=vis[g[k].se.fi]){
				da[k]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)if(da[i])ans++;
	cout<<ans;
	return 0;
}