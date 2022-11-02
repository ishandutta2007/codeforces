#include <bits/stdc++.h>
#define MAXS 1000007
using namespace std;
long long cntg[MAXS],cntd[MAXS];
int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int sz; scanf("%d",&sz);
		int t; scanf("%d",&t);
		bool op=true; int pr=t;
		for(int i=1;i<sz;i++)
		{
			int x; scanf("%d",&x);
			if(x>pr) op=false;
			pr=x;
		}
		if(op) cntg[t]++;
		if(op) cntd[pr]++;
	}
	long long res=0,cnt=0;
	for(int i=0;i<MAXS;i++)
	{
		cnt+=cntg[i];
		res+=cntd[i]*cnt;
	}
	long long nk=n; nk*=nk;
	printf("%I64d",nk-res);
}