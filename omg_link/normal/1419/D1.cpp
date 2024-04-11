#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,a[MN+5],b[MN+5];

int gn(){
	static int r=1;
	return r++;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n,std::greater<int>());
	for(int i=1;i<=n;i+=2)
		b[i] = a[gn()];
	for(int i=2;i<=n;i+=2)
		b[i] = a[gn()];
	b[0] = b[n+1] = 0;
	int ans = 0;
	for(int i=1;i<=n;i++)
		if(b[i]<b[i-1]&&b[i]<b[i+1]) ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
}