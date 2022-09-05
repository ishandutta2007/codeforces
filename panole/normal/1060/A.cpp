#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,t[10];
char s[1001];

int read()
{
	int p=0,f=1; char c=getchar();
	while (c>'9'||c<'0') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p*f;
}

int main()
{
	scanf("%d",&n); scanf("%s",s);
	memset(t,0,sizeof(t));
	for (int i=1; i<=n; i++) t[s[i-1]-'0']++;
	int ans=0;
	for (int i=1; i<=t[8]; i++)
		if (n-i>=i*10) ans=i;
	printf("%d\n",ans);
	return 0;
}