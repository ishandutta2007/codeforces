#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=500000;
const int Mod=1000000007;
int pow_2[Maxn+5];
void init(){
	pow_2[0]=1;
	for(int i=1;i<=Maxn;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
}
int n,m;
pair<int,int> a[Maxn+5];
int fa[Maxn+5];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	fa[fa_y]=fa_x;
}
int id[Maxn+5],id_len;
int all;
int main(){
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		fa[i]=i;
	}
	all=0;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		if(k==1){
			scanf("%d",&a[i].first);
			a[i].second=0;
		}
		else{
			scanf("%d%d",&a[i].first,&a[i].second);
			if(a[i].first<a[i].second){
				swap(a[i].first,a[i].second);
			}
		}
		if(find(a[i].first)==find(a[i].second)){
			continue;
		}
		id[++id_len]=i;
		merge(a[i].first,a[i].second);
	}
	printf("%d %d\n",pow_2[id_len],id_len);
	for(int i=1;i<=id_len;i++){
		printf("%d ",id[i]);
	}
	puts("");
	return 0;
}