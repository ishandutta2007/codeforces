#include<cstdio>
#include<cstring>

int n,d,sum;
char s[1001];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%s",&d,&s);
		if (sum==0&&s[0]!='S') {printf("NO"); return 0;}
		if (sum==20000&&s[0]!='N') {printf("NO"); return 0;}
		if (s[0]=='N') sum-=d;
		if (s[0]=='S') sum+=d;
		if (sum<0||sum>20000) {printf("NO"); return 0;}
	}
	if (sum==0) printf("YES"); else printf("NO");
	return 0;
}