#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;
int sum[M],n,s,ans[M],sa;
bool tong[M];

inline int read()
{
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

int main()
{
	s=1e6;n=read();
//	cout<<s<<endl<<n<<endl;
	for (int i=1;i<=n;i++)
	{
		int a=read();
//		printf("%d ",a);
		tong[a]=1;
		if (a>s+1-a)
			a=s+1-a;
		sum[a]++;
	}
//	cout<<endl;
	int sum2=0;
	for (int i=1;i<=s/2;i++)
	{
		if (sum[i]==1)
		{
			if (tong[i])
				ans[++sa]=s+1-i;
			else
				ans[++sa]=i;
		}
		if (sum[i]==2)
			sum2++;
	}
	for (int i=1;i<=s/2;i++)
	{
		if (sum2==0)
			break;
		if (sum[i]==0)
		{
			sum2--;
			ans[++sa]=i;
			ans[++sa]=s+1-i;
		}
	}
//	sort(ans+1,ans+sa+1);
	printf("%d\n",sa);
	for (int i=1;i<=sa;i++)
		printf("%d ",ans[i]);
	return 0;
}