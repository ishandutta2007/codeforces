#include<iostream>
using namespace std;
const int maxn = 2e6 + 50;
int fa[maxn];
int num[maxn];
int fnd(int x){
	if(x == fa[x]) return x;
	return fa[x] = fnd(fa[x]);
}
void link(int x,int y){
	int rx = fnd(x);
	int ry = fnd(y);
	if(rx == ry) return;
	fa[rx] = ry;
	num[ry] += num[rx];
}
int n,m;
int main(){
	cin>>n>>m;
	int tot = n + m;
	for(int i = 1;i <= n;++i) fa[i] = i,num[i] = 1;
	for(int i = 1;i <= m;++i){
		int k;scanf("%d",&k);
		if(k == 0) continue;
		int u;
		scanf("%d",&u);
		while(--k){
			int v;scanf("%d",&v);
			link(u,v);
		}
	}
	for(int i = 1;i <= n;++i){
		int rx = fnd(i);
		printf("%d",num[rx]);if(i < n)printf(" ");else printf("\n");
	}
}