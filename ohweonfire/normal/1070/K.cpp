#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],s;
vector<int> v;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if (s%k)
	{
		puts("No");
		return 0;
	}
	s/=k;
	int now=0,lst=-1;
	for (int i=0;i<n;i++)
	{
		now+=a[i];
		if (now==s)
		{
			v.push_back(i-lst);
			lst=i;
			now=0;
		}
		else if (now>s)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i=0;i<k;i++)
	{
		printf("%d ",v[i]);
	}
	return 0;
}