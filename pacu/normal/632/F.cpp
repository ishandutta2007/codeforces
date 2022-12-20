#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int A[2500][2500];
int a[10000000],b[10000000],v[10000000],cid[10000000];

bool cmp(int x,int y)
{
	return v[x]>v[y];
}

long long safe[2500][42];
long long tot[42];

int main()
{
	int N;
	scanf("%d",&N);
	int K = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&A[i][j]);
			if(i<j)
			{
				a[K] = i, b[K] = j;
				v[K] = A[i][j];
				cid[K] = K;
				K++;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(A[i][j]!=A[j][i])
			{
				printf("NOT MAGIC\n");
				return 0;
			}
		}
		if(A[i][i]!=0)
		{
			printf("NOT MAGIC\n");
			return 0;
		}
	}
	for(int i=0;i<N;i++)
		tot[i/60] |= (1LL<<(i%60));
	sort(cid,cid+K,cmp);
	int start = 0;
	for(int i=0;i<K;i++)
	{
		if(i<K-1 && v[cid[i+1]]==v[cid[i]])
			continue;
		for(int j=start;j<=i;j++)
		{
			//cout << a[cid[j]] << ' ' << b[cid[j]] << '\n';
			safe[a[cid[j]]][b[cid[j]]/60] |= (1LL<<((b[cid[j]]%60)));
			safe[b[cid[j]]][a[cid[j]]/60] |= (1LL<<((a[cid[j]]%60)));
		}
		for(int j=start;j<=i;j++)
		{
//			cout << "Check " << a[cid[j]] << ' ' << b[cid[j]] << '\n';
			for(int k=0;k<42;k++)
				if((safe[a[cid[j]]][k]|safe[b[cid[j]]][k]) != tot[k])
				{
					printf("NOT MAGIC\n");
					return 0;
				}
		}
		start = i+1;
	}
	printf("MAGIC\n");
	return 0;
}