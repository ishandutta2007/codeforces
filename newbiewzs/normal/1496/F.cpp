#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
#define pl pair<int,long long>
#define vi vector<int>
#define vl vector<long long>
#define N 505
#define mod 998244353
//#define int long long
using namespace std;
typedef long long ll;
int n,m,x,y;
vi v[N];
int f[N][N],g[N][N];
void prework(int u){
	queue<int>q;
	q.push(u);
	f[u][u]=0;g[u][u]=1;
	while(q.size()){
		int h=q.front();
		q.pop();
		for(int i=0;i<v[h].size();i++){
			if(f[u][v[h][i]]>f[u][h]+1){
				f[u][v[h][i]]=f[u][h]+1;
				g[u][v[h][i]]=g[u][h];
				q.push(v[h][i]);
			}
			else if(f[u][v[h][i]]==f[u][h]+1){
				g[u][v[h][i]]=(g[u][v[h][i]]+g[u][h]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	memset(f,10,sizeof(f));
	for(int i=1;i<=n;i++){
		prework(i);
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(g[i][k]>1){
				cout<<0<<" ";
				continue;
			}
			int ans=1;
			for(int j=1;j<=n;j++){
				if(f[i][j]+f[j][k]==f[i][k])continue;
				int tot=0;
				for(int l=0;l<v[j].size();l++){
					int to=v[j][l];
					if(f[j][i]==f[to][i]+1 and f[j][k]==f[to][k]+1){
						tot++;
					}
				}
				ans=(1ll*ans*tot)%mod;
			}
			printf("%d ",ans);
		}
		puts("");
	}
	return 0;
}