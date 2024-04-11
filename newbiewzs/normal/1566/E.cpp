#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<cmath> 
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
using namespace std;
int read(){
	char c=getchar();int x=1;int s=0;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
const int N=4e5+5;
vi v[N];
int n,x,y,siz[N],tong;
void dfs(int u,int fa){
	int cnt=1,tmp=0;
	for(unsigned int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
		dfs(v[u][i],u);
		cnt++;
		if(siz[v[u][i]]==1)tmp++;
	}
	siz[u]=cnt;
	if(tmp){
		tong=tong+tmp-1;
	}
	else{
		siz[u]=1;
	}
}
void solve(){
	n=read();
	for(int i=1;i<n;i++){
		x=read();y=read();
		v[x].pb(y);
		v[y].pb(x);
	}
	if(n==2){
		cout<<1<<'\n';
	}
	else{
		dfs(1,0);
		cout<<tong+1<<'\n';
	}
	for(int i=1;i<=n;i++)v[i].clear(),siz[i]=0;
	tong=0;
}
signed main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}