#include<bits/stdc++.h>
using namespace std;
int n,l,r,c,a[20],res;
void dfs(int x,int mi,int ma,int tot){
	if (x==n){
		if (ma>=mi+c&&tot>=l&&tot<=r) res++;
		return;
	}
	dfs(x+1,min(mi,a[x]),max(ma,a[x]),tot+a[x]);
	dfs(x+1,mi,ma,tot);
}
int main(){
	scanf("%d%d%d%d",&n,&l,&r,&c);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	dfs(0,10000000,0,0);
	printf("%d\n",res);
}