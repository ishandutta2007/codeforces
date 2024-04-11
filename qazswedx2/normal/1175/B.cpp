#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,st[1000005],tp,vis[1000005],fl=0,cnt=0;
ll nw=1,ans=0,maxn=(1ll<<32ll)-1ll;
char s[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		if(s[0]=='a')
		{
			ans=ans+nw;
			if(ans>maxn||cnt)
			{
				printf("OVERFLOW!!!");
				return 0;
			}
		}
		if(s[0]=='f')
		{
			int x;
			scanf("%d",&x);
			nw=nw*(ll)x;
			st[++tp]=x;
			vis[tp]=1;
			if(nw>maxn)
			{
				vis[tp]=0;
				nw=nw/x;
				fl=1;
				cnt++;
				//printf("OVERFLOW!!!");
				//return 0;
			}
		}
		if(s[0]=='e')
		{
			if(vis[tp]) nw=nw/st[tp];
			if(!vis[tp]) cnt--;
			tp--;
			if(vis[tp]) fl=0;
		}
	}
	printf("%I64d",ans);
	return 0;
}