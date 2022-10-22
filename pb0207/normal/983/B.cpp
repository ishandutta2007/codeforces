#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=5e3+1e2+7;

int n,f[N][N],q,a[N];

vector<int>v;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		v.clear();
		for(int j=0;j<=i-1;j++)
			if((j&(i-1))==j)
				v.push_back(j);
		for(int l=1;l<=n-i+1;l++)
		{
			int r=l+i-1;
			for(int q=0;q<v.size();q++)
				f[l][r]^=a[l+v[q]];
			if(i>=2)
			{
				f[l][r]=max(f[l][r],f[l+1][r]);
				f[l][r]=max(f[l][r],f[l][r-1]);
			}
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",f[l][r]);
	}
}