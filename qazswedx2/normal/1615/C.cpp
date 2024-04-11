#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
char a[1000005],b[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s%s",&n,a+1,b+1);
		int ct[2][2];
		memset(ct,0,sizeof(ct));
		for(int i=1;i<=n;i++)
			ct[a[i]-'0'][b[i]-'0']++;
		int ans=1e9;
		if(ct[0][1]==ct[1][0]) ans=min(ans,ct[0][1]+ct[1][0]);
		if(ct[0][0]==ct[1][1]-1) ans=min(ans,ct[0][0]+ct[1][1]);
		if(ans>1e8) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}