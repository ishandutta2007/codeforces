#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

char a[N],b[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		int ok=1;
		for(int i=1;i<=n;i++)
			ok&=a[i]<=b[i];
		if(!ok)
		{
			puts("-1");
			continue;
		}
		int ans=0;
		for(int i=0;i<20;i++)
		{
			int mn=100;
			for(int j=1;j<=n;j++)
				if(a[j]-'a'==i)
				{
					if(b[j]-'a'!=i)
						mn=min(mn,b[j]-'a');
				}
			if(mn!=100)
			{
				ans++;
				for(int j=1;j<=n;j++)
					if(a[j]-'a'==i&&b[j]!=a[j])
						a[j]=mn+'a';
			}
		}
		printf("%d\n",ans);
	}
}