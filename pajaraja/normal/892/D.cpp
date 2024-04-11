#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[22];
int b[22];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a,a+n);
	for(int i=1;i<n;i++) b[a[i].second]=a[i-1].first;
	b[a[0].second]=a[n-1].first;
	for(int i=0;i<n;i++) printf("%d ",b[i]);
}