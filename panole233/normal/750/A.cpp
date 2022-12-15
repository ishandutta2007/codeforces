#include<cstdio>
#include<cstring>

int n,k,s,ans;

int main()
{
	scanf("%d%d",&n,&k);
	k=240-k;
	s=0; ans=0;
	for (int i=1; i<=n&&s+i*5<=k; i++) s+=i*5,ans++;
	printf("%d",ans);
	return 0;
}