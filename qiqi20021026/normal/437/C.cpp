#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,x,y,ans,a[3000];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){scanf("%d%d",&x,&y); ans+=min(a[x],a[y]);}
	printf("%d\n",ans);
	
	return 0;
}