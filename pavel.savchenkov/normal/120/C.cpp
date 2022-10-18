#include <cstdio>

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n+1]; int res=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); int j=0;
		while (a[i]>=k&j<=2) 
		{ a[i]-=k;j++;}
		res+=a[i];
	}
	printf("%d",res);
	return 0;
}