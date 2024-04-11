#include<bits/stdc++.h>
using namespace std;

const int M=100010;
int n,a[M],s,sum;

int main()
{
	cin>>n>>s;
	for (int i=1;i<n;i++)
	{
		int a1,a2;
		cin>>a1>>a2;
		a[a1]++,a[a2]++;
	}
	for (int i=1;i<=n;i++)
		if (a[i]==1)
			sum++;
	double ans=s*2.0/sum;
	printf("%.15lf",ans);
	return 0;
}

//11 
//00ans
//
//