#include <cstdio>
#include <iostream>
using namespace std;
#define MOD 1000000007
#define INF 1000000006

char A[5001];

int leq[5000][5001];	//cur, length
int num[5000][5001];
int snum[5000][5001];
int seq[5000][5001];
int low[5000][5001];

int main()
{
	scanf("%s",A);
	int N = 0;
	for(;A[N]!='\0';N++)
		;
	for(int l=1;2*l<=N;l++)
	{
		leq[N-1][l] = 0;
		for(int j=1;j<=l;j++)
		{
			if(A[N-1-2*l+j]<A[N-1-l+j])
			{
				leq[N-1][l] = l;
				break;
			}
			else if(A[N-1-2*l+j]==A[N-1-l+j])
				leq[N-1][l]++;
			else
				break;
		}
		for(int c=N-2;c>=2*l-1;c--)
		{
			if(A[c+1-2*l]<A[c+1-l])
				leq[c][l] = l;
			else if(A[c+1-2*l]==A[c+1-l])
				leq[c][l] = min(1+leq[c+1][l],l);
			else
				leq[c][l] = 0;
		}
	}
	for(int c=0;c<N;c++)
	{
		snum[c][0] = 0;
		low[c][0] = INF;
		for(int l=1;l<=N;l++)
		{
			if((l>(c+1))||(A[c+1-l]=='0'))
			{
				num[c][l] = 0;
				snum[c][l] = snum[c][l-1];
				seq[c][l] = INF;
				low[c][l] = low[c][l-1];
				continue;
			}
			if(l==(c+1))
			{
				num[c][l] = 1;
				snum[c][l] = (snum[c][l-1]+1)%MOD;
				seq[c][l] = low[c][l] = 1;
				continue;
			}
			num[c][l] = snum[c-l][l-1];
			seq[c][l] = 1+low[c-l][l-1];
			if(leq[c][l]==l)
			{
				num[c][l] = (num[c][l]+num[c-l][l])%MOD;
				seq[c][l] = min(seq[c][l],1+seq[c-l][l]);
			}
			snum[c][l] = (snum[c][l-1]+num[c][l])%MOD;
			low[c][l] = min(low[c][l-1],seq[c][l]);
		}
	}
	int ans = 0;
	for(int l=1;l<=N;l++)
		ans = (ans+num[N-1][l])%MOD;
	printf("%d\n",ans);
	int minseq = INF;
	int cur = 0;
	for(int l=1;l<=20 && l<=N;l++)
	{
		cur += (A[N-l]=='1')<<(l-1);
		if(seq[N-1][l]<INF)
			minseq = min(minseq,cur+seq[N-1][l]);
	}
	if(minseq == INF)
	{
		for(int l=21;l<=N;l++)
		{
			if(seq[N-1][l]<INF)
			{
				cur = 0;
				for(int j=N-l;j<N;j++)
					cur = ((2*cur)%MOD + (A[j]=='1'))%MOD;
				minseq = cur+seq[N-1][l];
				break;
			}
		}
	}
	printf("%d\n",minseq);
}