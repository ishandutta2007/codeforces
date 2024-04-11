#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],b[1000005];
char s[1000005],t[1000005];
int main()
{
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	int nw=1;
	for(int i=1;i<=n;i++)
	{
		if(nw<=m&&s[i]==t[nw])
		{
			a[nw]=i;
			nw++;
		}
	}
	nw=m;
	for(int i=n;i>0;i--)
		if(nw&&s[i]==t[nw])
		{
			b[nw]=i;
			nw--;
		}
	int ans=0;
	for(int i=1;i<m;i++)
		ans=max(ans,b[i+1]-a[i]);
	printf("%d\n",ans);
	return 0;
}