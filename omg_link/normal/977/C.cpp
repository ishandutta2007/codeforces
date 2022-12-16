#include <stdio.h>
#include <algorithm>
#define MN 200000
int n,k,a[MN+5];
int main(){
	scanf("%d%d",&n,&k);
	a[0]=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	if(k<n&&a[k]==a[k+1]) printf("-1");
	else printf("%d",a[k]);
}