#include<cstdio>
#include<algorithm>
using namespace std;
int ans,tans,n,d;
char ch;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d\n",&n,&d);
	for(int i=1;i<=d;i++)
	{
		int sum=0;for(int j=1;j<=n;j++){scanf("%c",&ch);sum+=ch-'0';}
		if(sum==n){ans=max(ans,tans);tans=0;}else tans++;
		scanf("\n");
	}
	ans=max(ans,tans);
	printf("%d",ans);
	return 0;
}