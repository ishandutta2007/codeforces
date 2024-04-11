#include<bits/stdc++.h>
using namespace std;
bitset<2010> b,c;
int v[1010],x[1010];
int main()
{
	int n,k,t1;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&t1);
		v[t1]=1;
	}
	int o=0;
	for(int i=0;i<=1000;i++)
		if(v[i])
		{
			o++;
			x[o]=i-n;
			b[i-n+1000]=1;
		}
	for(int i=1;i<=1010;i++)
	{
		if(b[1000])
		{
			cout<<i<<endl;
			return 0;
		}
		c=0;
		for(int j=1;j<=o;j++)
			if(x[j]>=0)
				c=c|(b<<x[j]);
			else
				c=c|(b>>(-x[j]));
		b=c;
	}
	cout<<-1;
	
}