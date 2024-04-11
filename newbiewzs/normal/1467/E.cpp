#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=2e5+55;
int n,cn[N],lsh[N],a[N],tong[N];
vector<int>v[N];
int cf[N];
int st[N],en[N],tot;
void dfs(int u,int fa){
	st[u]=++tot;
	cn[a[u]]++;
	int jl=cn[a[u]];
	int hh=cn[a[u]];
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
		hh=cn[a[u]];
		dfs(v[u][i],u);
		if(cn[a[u]]-hh>0){
			cf[1]++;
			cf[st[v[u][i]]]--;
			cf[en[v[u][i]]+1]++;
		}
	}
	en[u]=tot;
	if(cn[a[u]]-jl+1<tong[a[u]]){
		cf[st[u]]++;cf[en[u]+1]--;
	}
}
int x,y;
int main(){
	n=read();
	for(int i=1;i<=n;i++)lsh[i]=a[i]=read();
	for(int i=1;i<n;i++){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	sort(lsh+1,lsh+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+n+1,a[i])-lsh;
	for(int i=1;i<=n;i++){
		tong[a[i]]++;
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++){
		cf[i]=cf[i-1]+cf[i];
	}
	for(int i=1;i<=n;i++){
		if(!cf[i])ans++;
	}
	cout<<ans;
	return 0;
}