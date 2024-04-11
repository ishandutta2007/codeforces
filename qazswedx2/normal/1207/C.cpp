#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,a,b;
ll f[1000005][2];
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		scanf("%s",s+1);
		for(int i=0;i<=n;i++)
			f[i][0]=f[i][1]=1e15;
		f[0][0]=b;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				f[i][0]=min(f[i-1][1]+2*a,f[i-1][0]+a)+b;
				f[i][1]=min(f[i-1][0]+2*a,f[i-1][1]+a)+2*b; 
			}
			else
			{
				f[i][1]=f[i-1][1]+2*b+a;
			}
		}
		printf("%I64d\n",f[n][0]);
	}
	return 0;
}