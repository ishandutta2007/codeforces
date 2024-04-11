#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,a[N],T;

int f[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		fill(f+1,f+n+1,-1);
		f[0]=0;
		a[0]=1e9;
		for(int i=1;i<=n;i++)
		{
			if(f[i-1]>a[i])
				break;
			f[i]=max(a[i]-a[i-1]+f[i-1],f[i-1]);
		}
		puts(f[n]!=-1?"YES":"NO");
	}
}