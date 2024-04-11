#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s=0;
	char c=getchar();
	int x=1;
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
const int N=2e5+5;
vector<int>son[N],v[N],cd[N];
int T,n,maxdep,a[N];
int fu[N],f[N];
int maxx[N],minn[N];
int cmp(int x,int y){
	return a[x]>a[y];
}
int cmp1(int x,int y){
	return a[x]>a[y];
}
void dfs(int u,int fa,int deep){
	v[deep].push_back(u);
	cd[deep].push_back(u);
	fu[u]=fa;
	maxdep=max(maxdep,deep);
	if(a[u]>maxx[deep]){
		maxx[deep]=a[u];
	}
	if(a[u]<minn[deep]){
		minn[deep]=a[u];
	}
	for(int i=0;i<son[u].size();i++){
		dfs(son[u][i],u,deep+1);
	}
}
int x;
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=2;i<=n;i++){
			x=read();
			son[x].push_back(i);
		}
		for(int i=2;i<=n;i++){
			a[i]=read();
			minn[i]=1e9;
		}
		dfs(1,0,1);
		f[1]=0;
		for(int i=2;i<=maxdep;i++){
			for(int k=0;k<v[i].size();k++){
				int u=v[i][k];
				f[u]=max(f[fu[u]]+abs(a[u]-maxx[i]),f[fu[u]]+abs(a[u]-minn[i]));
			}
			sort(cd[i].begin(),cd[i].end(),cmp);
			int head=0;int tail=cd[i].size()-1;
			int qz=-1e9;
			for(int k=0;k<cd[i].size();k++){
				int u=cd[i][k];
				while(head<=tail and a[cd[i][head]]>=a[u]){
					qz=max(qz,f[fu[cd[i][head]]]+a[cd[i][head]]);
					head++;
				}
				f[u]=max(f[u],qz-a[u]);
			}
			sort(cd[i].begin(),cd[i].end(),cmp1);
			head=0;tail=cd[i].size()-1;
			qz=-1e9;
			for(int k=0;k<cd[i].size();k++){
				int u=cd[i][k];
				while(head<=tail and a[cd[i][head]]<=a[u]){
					qz=max(qz,f[fu[cd[i][head]]]-a[cd[i][head]]);
					head++;
				}
				f[u]=max(f[u],qz+a[u]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,f[i]),f[i]=0;
		for(int i=1;i<=n;i++)vector<int>().swap(son[i]);
		for(int i=1;i<=n;i++)vector<int>().swap(v[i]);
		for(int i=1;i<=n;i++)vector<int>().swap(cd[i]);
		maxdep=0;
		for(int i=1;i<=n;i++)maxx[i]=0,fu[i]=0,minn[i]=-1e9;
		printf("%lld\n",ans);
	}
	return 0;
}