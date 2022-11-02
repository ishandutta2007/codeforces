#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=1e4+5;
int T,n;
int a[N];
int rt;
vector<int>v[N];
int cdq(int l,int r){
	if(l>r)return 0;
	int maxx=0;int jl;
	for(int i=l;i<=r;i++){
		if(a[i]>maxx)maxx=a[i],jl=i;
	}
	v[jl].push_back(cdq(l,jl-1));
	v[jl].push_back(cdq(jl+1,r));
	return jl;
}
int deep[N];
void dfs(int u,int fa){
	if(!u)return ;
	deep[u]=deep[fa]+1;
	for(int i=0;i<v[u].size();i++){
		dfs(v[u][i],u);
	}
}
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		rt=cdq(1,n);
		dfs(rt,0);
		for(int i=1;i<=n;i++)cout<<deep[i]-1<<" ";
		puts("");
		for(int i=1;i<=n;i++)v[i].clear(); 
	}
	return 0;
}