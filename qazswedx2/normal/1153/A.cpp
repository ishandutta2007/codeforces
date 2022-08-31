#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,s[100005],d[100005],t,ans=99999999,id;
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		int oans=ans;
		scanf("%d%d",&s[i],&d[i]);
		if(s[i]<=t)
		{
			ans=min(ans,(d[i]-(t-s[i])%d[i]+d[i])%d[i]);
		}
		else ans=min(ans,s[i]-t);
		if(oans!=ans) id=i;
	}
	printf("%d",id);
	return 0;
}