#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[1001],ans=2147483647;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int c;
		scanf("%d",&c);
		a[c]++;
	}
	for(int i=1;i<=n;i++) ans=min(ans,a[i]);
	printf("%d\n",ans);
}