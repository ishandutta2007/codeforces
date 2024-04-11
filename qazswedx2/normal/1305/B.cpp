#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t,a[100005],at,b[100005],bt,tans[1000005];
char s[100005];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='(') a[++at]=i;
		else b[++bt]=i;
	reverse(b+1,b+bt+1);
	for(int i=1;i<=min(at,bt);i++)
		if(a[i]<b[i])
		{
			tans[++t]=a[i];
			tans[++t]=b[i];
		}
	if(!t) printf("0\n");
	else
	{
		printf("1\n%d\n",t);
		sort(tans+1,tans+t+1);
		for(int i=1;i<=t;i++)
			printf("%d ",tans[i]);
	}
	return 0;
}