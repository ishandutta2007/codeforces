#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n;

char a[N],b[N];

vector<int>v;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		v.clear();
		for(int i=1,j;i<=n;i=j+1)
		{
			j=i;
			while(j+1<=n&&a[j+1]==a[j])
				j++;
			if(j!=n)
				v.push_back(j);
		}
		if(b[n]!=a[n])
			v.push_back(n);
		for(int i=n,j;i>=1;i=j-1)
		{
			j=i;
			while(j-1>=1&&b[j-1]==b[j])
				j--;
			if(j-1)
				v.push_back(j-1);
		}
		printf("%d ",(int)v.size());
		for(int i=0;i<v.size();i++)
			printf("%d ",v[i]);
		puts("");
	}	
}