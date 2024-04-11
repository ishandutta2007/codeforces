#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
#define int long long
const int N=1005;
const int mod=1e9+7;
int T,n,m;
int f[N][N];
int dfs(int u,int k){
	if(!k)return 0;
	if(u==1)return 0;
	if(f[u][k]!=-1)return f[u][k];
	f[u][k]=(dfs(u,k-1)+dfs(u-1,n-k)+1)%mod;
	return f[u][k];
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=max(n,m);i++)for(int k=1;k<=max(n,m);k++)f[i][k]=-1;
		cout<<dfs(m,n)+1<<endl;
	}
	return 0;
}