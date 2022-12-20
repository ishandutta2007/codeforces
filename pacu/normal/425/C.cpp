#include <cstdio>
#include <iostream>
using namespace std;
#define INF 2000000000

int N,M,s,e;

int first[100000][300];
int A[100000],B[100000];
int floc[100001];

int main()
{
	scanf("%d %d %d %d",&N,&M,&s,&e);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	for(int j=0;j<M;j++)
		scanf("%d",&B[j]);
	for(int i=0;i<=100000;i++)
		floc[i] = INF;
	for(int j=M-1;j>=0;j--)
		floc[B[j]] = j;
	for(int i=0;i<N;i++)
		first[i][0] = floc[A[i]];
	for(int k=1;k<(s/e);k++)
	{
//		cout << "----" << k+1 << endl;
		for(int i=0;i<=100000;i++)
			floc[i] = INF;
		int p = M-1;
		int x = M;
		for(int i=0;i<N;i++)
		{
//			cout << i << " " << x << endl;
			first[i][k] = floc[A[i]];
			x = min(x,first[i][k-1]);
			for(;p>x;p--)
				floc[B[p]] = p;
		}
	}
	int best = -1;
	for(int k=0;k<(s/e);k++)
		for(int i=0;i<N;i++)
			if(((k+1)*e + (i+1) + (first[i][k]+1))<=s)
				best = k;
	printf("%d\n",best+1);
	return 0;
}