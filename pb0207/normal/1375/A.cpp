#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			int x=(a[i]>=0)?a[i]:-a[i];
			if(i&1)
				printf("%d ",x);
			else
				printf("%d ",-x);
		}
		puts("");
	}
}