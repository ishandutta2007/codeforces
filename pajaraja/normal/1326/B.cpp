#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
int b[MAXN],a[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	int mx=0;
	for(int i=0;i<n;i++)
	{
		a[i]=mx+b[i];
		mx=max(mx,a[i]);
	}
	for(int i=0;i<n;i++) printf("%d ",a[i]);
}