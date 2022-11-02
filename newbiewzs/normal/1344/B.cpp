#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=1050;
int T;
int n,m;
char a[N][N];
bool pd[N][N];
int vis[N],tong[N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y){
	if(pd[x][y])return ;
	if(x>n || x<1 || y<1 || y>m)return ;
	pd[x][y]=1;
	for(int i=0;i<4;i++){
		if(a[x+dx[i]][y+dy[i]]=='#')dfs(x+dx[i],y+dy[i]);
	}
}
void solve(){
	n=read();m=read();
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	bool flag=0;
	for(int i=1;i<=n;i++){
		int st=0,ed=0;
		for(int k=1;k<=m;k++)if(a[i][k]=='#'){
			st=k;break;
		}
		for(int k=m;k>=1;k--)if(a[i][k]=='#'){
			ed=k;break;
		}
		if(st && ed){
			for(int k=st;k<=ed;k++)if(a[i][k]=='.')flag=1;
		}
	}
	for(int i=1;i<=m;i++){
		int st=0,ed=0;
		for(int k=1;k<=n;k++)if(a[k][i]=='#'){
			st=k;break;
		}
		for(int k=n;k>=1;k--)if(a[k][i]=='#'){
			ed=k;break;
		}
		if(st && ed){
			for(int k=st;k<=ed;k++)if(a[k][i]=='.')flag=1;
		}
	}
	int se=0;
	for(int i=1;i<=n;i++){
		int zs=0;
		for(int k=1;k<=m;k++){
			if(a[i][k]=='#')zs++,se++;
		}
		vis[i]=zs;
	}
	for(int i=1;i<=m;i++){
		int tmp=0;
		for(int k=1;k<=n;k++){
			if(a[k][i]=='#')tmp++;
		}
		tong[i]=tmp;
	}
	if(se==0){
		cout<<0;return ;
	}
	for(int i=1;i<=m;i++){
		if(!tong[i]){
			int tmp=0;
			for(int k=1;k<=n;k++)if(!vis[k])tmp++;
			if(!tmp)flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int tmp=0;
			for(int k=1;k<=m;k++)if(!tong[k])tmp++;
			if(!tmp)flag=1;
		}
	}
	if(flag){
		puts("-1");return;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			if(!pd[i][k] and a[i][k]=='#')ans++,dfs(i,k);
		}
	}
	cout<<ans;
	return ;
}
signed main(){
	T=1;
	while(T--){
		solve();
	}
	return 0;
}