#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int A[1000000];
int cid[1000000];

bool cmp(int a,int b)
{
	return A[a]<A[b];
}

int nxt[1000000];
int pre[1000000];

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
	for(int i=0;i<N;i++)
		nxt[i] = i+1, pre[i] = i-1;
	long long sumMax = 0;
	for(int i=0;i<N;i++)
	{
		int cur = cid[i];
		int l = cur - pre[cur];
		int r = nxt[cur] - cur;
		sumMax += A[cur]*((long long)l)*((long long)r);
		if(pre[cur]!=-1) nxt[pre[cur]] = nxt[cur];
		if(nxt[cur]!=N) pre[nxt[cur]] = pre[cur];
	}
	for(int i=0;i<N;i++)
		nxt[i] = i+1, pre[i] = i-1;
	long long sumMin = 0;
	for(int i=N-1;i>=0;i--)
	{
		int cur = cid[i];
		int l = cur - pre[cur];
		int r = nxt[cur] - cur;
		sumMin += A[cur]*((long long)l)*((long long)r);
		if(pre[cur]!=-1) nxt[pre[cur]] = nxt[cur];
		if(nxt[cur]!=N) pre[nxt[cur]] = pre[cur];
	}
	printf("%I64d\n",sumMax-sumMin);
}