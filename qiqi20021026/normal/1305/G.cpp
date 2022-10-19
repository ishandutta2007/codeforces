#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,m,a[N],sz[N],fa[N];
long long ans;

int gfa(int x){
	return x==fa[x]?x:fa[x]=gfa(fa[x]);
}

int main(){
	scanf("%d",&n); m=18;
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	sz[0]=1;
	for (int i=1;i<=n;++i){
		++sz[a[i]];
		ans-=a[i];
	}
	for (int i=0;i<1<<m;++i) fa[i]=i;
	for (int i=(1<<m)-1;i;--i){
		for (int j=i;j>i/2;j=(j-1)&i){
			int k=i^j;
			int u=gfa(j),v=gfa(k);
			if (u!=v&&sz[u]&&sz[v]){
				ans+=1LL*i*(sz[u]+sz[v]-1);
				sz[v]=1; fa[u]=v;
			}
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}