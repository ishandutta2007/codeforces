# include <cstdio>
# include <iostream>
# include <algorithm>

using namespace std;

int val[100000],col[100000];
long long best[100001];
long long inf=-1000000000000000000ll;

int main()
{
	int N,Q;
	scanf("%d%d",&N,&Q);

	for(int i=0;i<N;i++)
		scanf("%d",val+i);
	for(int i=0;i<N;i++)
		scanf("%d",col+i);

	for(int q=0;q<Q;q++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		long long ans=0;
		best[0]=0;
		for(int i=1;i<100001;i++)
			best[i]=inf;

		int col1=0,col2=1;
		for(int i=0;i<N;i++)
		{
			int &c=col[i],&v=val[i];
			if(best[c]!=inf)best[c]=max(best[c],best[c]+a*(long long)v);
			if(c==col1)
			{
				if(best[col2]!=inf)best[c]=max(best[c],best[col2]+b*(long long)v);
			}
			else best[c]=max(best[c],best[col1]+b*(long long)v);

			if(best[c]>best[col1])
			{
				col2=col1;
				col1=c;
			}
			else if((c!=col1)&&(best[c]>best[col2]))col2=c;

			ans=max(ans,best[c]);
		}
		cout<<ans<<endl;
	}
	return 0;
}