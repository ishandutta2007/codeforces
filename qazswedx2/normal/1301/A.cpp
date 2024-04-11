#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
char a[100005],b[100005],c[100005]; 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s",a+1,b+1,c+1);
		n=strlen(a+1);
		int fl=1;
		for(int i=1;i<=n;i++)
			if(c[i]!=b[i]&&c[i]!=a[i])
				fl=0;
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}