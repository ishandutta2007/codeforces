#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int f[44001],T,t[11],tn;

int main()
{
	scanf("%d",&T);
	f[0]=1;
	for (int i=1; i<=40000; i++)
	{
		int x=i; tn=0;
		while (x) t[++tn]=x%10,x/=10;
		bool bo=1;
		for (int j=1; j<=tn; j++) if (t[j]!=t[tn-j+1]) bo=0;
		if (!bo) continue;
		for (int j=0; i+j<=40000; j++)
			f[i+j]=(f[i+j]+f[j]>=mod?f[i+j]+f[j]-mod:f[i+j]+f[j]);
	}
	while (T--)
	{
		int n;scanf("%d",&n);printf("%d\n",f[n]);
	}
	return 0;
}