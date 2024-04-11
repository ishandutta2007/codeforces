#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,k,a[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int fl[15];
		fl[0]=fl[1]=fl[2]=fl[3]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<=2) fl[a[i]]++;
		}
		sort(a+1,a+n+1);
		if(!fl[1]) printf("YES\n");
		else
		{
			int fll=0;
			for(int i=1;i<n;i++)
				if(a[i]+1==a[i+1]) fll=1;
			if(fll) printf("NO\n");
			else printf("YES\n");
		}
	}
}