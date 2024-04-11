#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
char s[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		if(n%2)
		{
			int fl=0;
			for(int i=1;i<=n;i+=2)
				if((s[i]-'0')%2)
					fl=1;
			if(fl==1) printf("1\n");
			else printf("2\n");
		}
		else
		{
			int fl=0;
			for(int i=2;i<=n;i+=2)
				if((s[i]-'0')%2==0)
					fl=1;
			if(fl==1) printf("2\n");
			else printf("1\n");
		}
	}
	return 0;
}