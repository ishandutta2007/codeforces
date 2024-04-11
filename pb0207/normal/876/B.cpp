#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=2e6+1e3+7;

int n,k,m;

int a[N],tot[N];

int main()
{
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],tot[a[i]%m]++;
	for(int i=0;i<m;i++)
		if(tot[i]>=k)
		{
			puts("Yes");
			int x=0;
			for(int j=1;j<=n;j++)
				if(a[j]%m==i)
				{
					x++;
					printf("%d ",a[j]);
					if(x==k)
						exit(0);
				}
		}
	puts("No");
}