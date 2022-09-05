#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long n,a,b;
int t[20];

int read()
{
	int p=0,f=1; char c=getchar();
	while (c>'9'||c<'0') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p*f;
}

int main()
{
	scanf("%I64d",&n); a=0;
	while (a*10+9<=n) a=a*10+9;
	b=n-a; t[0]=0;
	while (b) t[++t[0]]=b%10,b/=10;
	int ans=0;
	for (int i=1; i<=t[0]; i++) ans+=t[i];
	t[0]=0;
	while (a) t[++t[0]]=a%10,a/=10;
	for (int i=1; i<=t[0]; i++) ans+=t[i];
	printf("%d\n",ans);
	return 0;
}