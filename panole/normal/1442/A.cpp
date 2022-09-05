#include<bits/stdc++.h>
using namespace std;

int n,T,a[30010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		int la1=a[1],la2=0;
		bool bo=1;
		for (int i=2; i<=n; i++)
		{
			if (a[i]<la2) {bo=0; break;}
			a[i]-=la2;
			if (a[i]<la1) la1=a[i];
			else la2+=a[i]-la1;
		}
		puts(bo?"YES":"NO");
	}
	return 0;
}