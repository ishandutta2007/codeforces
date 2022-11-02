#include<cstdio>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
long long ans;
char s[500010],t[500010];
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int last=1;
	rep(i,n)
	{
		last=(last-2)*2+2+(s[i]=='a')+(t[i]=='b');
		if(last>=k)
		{
			ans+=1ll*k*(n-i+1);
			break;
		}
		else ans+=last;
	}
	printf("%lld\n",ans);
	return 0;
}