#include<cstdio>
char a[300011];
int main()
{
	long long n,ans=0;scanf("%lld%s",&n,a+1);
    for(int i=1,j=2;i<=n;i=j)
    {
        while(a[j]==a[i])++j;
        if(j<=n)ans-=j-i;
		if(i>1)ans-=j-i-1;
    }
    printf("%lld",ans+n*(n-1)/2);
}