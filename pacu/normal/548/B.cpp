#include <cstdio>
using namespace std;

int A[500][500];
int high[500];
int N,M,Q;

int main()
{
	scanf("%d %d %d",&N,&M,&Q);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",&A[i][j]);
	for(int i=0;i<N;i++)
	{
		int m = 0;
		int c = 0;
		for(int j=0;j<M;j++)
		{
			if(A[i][j])
				c++;
			else
				c = 0;
			if(c>m) m = c;
		}
		high[i] = m;
	}
	int a,b;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&a,&b);
		a--,b--;
		A[a][b] ^= 1;
		int m = 0;
		int c = 0;
		for(int j=0;j<M;j++)
		{
			if(A[a][j])
				c++;
			else
				c = 0;
			if(c>m) m = c;
		}
		high[a] = m;
		int ans = 0;
		for(int j=0;j<N;j++)
			if(high[j]>ans)
				ans = high[j];
		printf("%d\n",ans);
	}
}