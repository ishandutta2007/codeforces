#include<bits/stdc++.h>
using namespace std;

int n,a[101],use[101];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),use[i]=0;
		int now=n-1;
		for(int i=1;i<=n&&now>0;i++)
		{
			int pos;
			for(int j=1;j<=n;j++)
				if(a[j]==i)
					pos=j;
			int np=pos-1;
			while(!use[np]&&now>0&&a[np]>a[np+1])
				now--,swap(a[np],a[np+1]),use[np]=1,np--;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
	}
}