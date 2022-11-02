#include <bits/stdc++.h>
using namespace std;
int st[27];
int main()
{
	st[0]=1; for(int i=1;i<27;i++) st[i]=st[i-1]*2;
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<27;i++)
		{
			if(a==st[i]-1)
			{
				bool pr=true;
				for(int k=2;k*k<=a;k++) if(a%k==0) {printf("%d",a/k); pr=false; break;}
				if(pr) printf("%d",1);
				break;
			}
			if(a<st[i]-1) {printf("%d",st[i]-1); break;}
		}
		printf("\n");
	}
}