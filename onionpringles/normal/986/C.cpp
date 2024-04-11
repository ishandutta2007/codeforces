#include <bits/stdc++.h>
using namespace std;
const int N=22;
int a[1<<N],d[1<<N],par[1<<N];
int find(int i){
	return par[i]<0?i:(par[i]=find(par[i]));
}
void merge(int i,int j){
	if(i<0 || j<0)return;
	i=find(i);j=find(j);
	if(i==j)return;
	if(par[i]<par[j])swap(i,j);
	par[j]+=par[i];par[i]=j;
}
int Do(int u){
	if(d[u]!=-2)return d[u];
	d[u]=a[u];
	for(int i=0;i<N;i++){
		if(!(u&1<<i))continue;
		if(d[u]<0){
			d[u]=Do(u^1<<i);
		}
		else merge(d[u],Do(u^1<<i));
	}
	return d[u];
}
int main(){
	int m;scanf("%*d%d",&m);
	for(int i=0;i<1<<N;i++)a[i]=-1;
	for(int i=0;i<1<<N;i++)d[i]=-2;
	for(int i=0;i<m;i++){
		int x;scanf("%d",&x);a[x]=i;
	}
	for(int i=0;i<m;i++)par[i]=-1;
	int ans=0;
	for(int i=0;i<1<<N;i++){
		if(a[i]<0)continue;
		merge(a[i],Do(((1<<N)-1)^i));
	}
	for(int i=0;i<1<<N;i++){
		if(a[i]>=0 && par[a[i]]<0)ans++;
	}
	printf("%d\n",ans);
}