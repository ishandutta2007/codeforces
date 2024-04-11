#include <cstdio>
using namespace std;

int p[1000001];

int cnt[1000001];
int A[1000000];
int N,M;

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		if(A[i] <= M)
		{
			cnt[A[i]]++;
		}
	}
	for(int i=1;i<=M;i++)
		for(int j=i;j<=M;j+=i)
			p[j] += cnt[i];
	int mx = 1;
	for(int i=1;i<=M;i++)
		if(p[i]>p[mx])
			mx = i;
	int ans = 0;
	for(int i=0;i<N;i++)
		if(mx%A[i] == 0)
			ans++;
	printf("%d %d\n",mx,ans);
	for(int i=0;i<N;i++)
		if(mx%A[i] == 0)
			printf("%d ",i+1);
	printf("\n");
			
}