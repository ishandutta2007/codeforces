#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m;
char a[100005],b[100005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s%s",a+1,b+1);
		int fl=1;
		for(int i=2;i<=m;i++)
			if(b[i]!=a[n-(m-i)])
				fl=0;
		int fl0=0;
		for(int i=1;i<=n-m+1;i++)
		{
			if(a[i]==b[1]) fl0=1;
		}
		if(fl&&fl0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}