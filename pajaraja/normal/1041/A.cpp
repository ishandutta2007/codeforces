#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,mi=1000000001,ma=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		mi=min(mi,t);
		ma=max(ma,t);
	}
	printf("%d",ma+1-mi-n);
}