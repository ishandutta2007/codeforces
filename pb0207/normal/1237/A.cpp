#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1)
			printf("%d\n",flag==0?(int)floor((double)a[i]/2):(int)ceil((double)a[i]/2)),flag^=1;
		else
			printf("%d\n",a[i]/2);
	}
}