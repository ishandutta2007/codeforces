#include<bits/stdc++.h>
using namespace std;

int T,n,a[200010],s1;
long long s2;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n),s1=0,s2=0;
		for (int i=1; i<=n; i++) scanf("%d",&a[i]),s1^=a[i],s2+=a[i];
		s2+=s1;
		printf("2\n%d %I64d\n",s1,s2);
	}
	return 0;
}