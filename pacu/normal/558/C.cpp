#include <cstdio>
#include <iostream>
using namespace std;

int A[100000];
int N;

int cnt[100001];
int nreach[100001];
long long ans[100001];
int dist[100001];

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		cnt[A[i]]++;
	}
	for(int i=100000;i>=1;i--)
	{
		nreach[i] = cnt[i];
		if(2*i <= 100000)
			nreach[i] += nreach[2*i];
		if(2*i+1 <= 100000)
			nreach[i] += nreach[2*i+1];
	}
	for(int i=100000;i>=1;i--)
	{
		if(2*i <= 100000)
			dist[i] += dist[2*i]+nreach[2*i];
		if(2*i+1 <+ 100000)
			dist[i] += dist[2*i+1]+nreach[2*i+1];
	}
	ans[1] = dist[1];
	long long best = ans[1];
	for(int k=2;k<=100000;k++)
	{
		if(nreach[k]<N && (k%2))
			ans[k] = 1000000000;
		else
			ans[k] = ans[k/2]+N-2*nreach[k];
		best = min(best,ans[k]);
	}
	cout << best << '\n';
}