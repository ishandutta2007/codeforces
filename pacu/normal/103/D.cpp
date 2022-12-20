#include <cstdio>
#include <algorithm>
using namespace std;

int w[300000];

int a[300000];
int b[300000];
int qid[300000];
long long qans[300000];
long long ans[300000];
int N,Q;

bool cmp(int x,int y)
{
	return b[x]<b[y];
}

void calc(int bb)
{
	for(int i=N-1;i>=0;i--)
	{
		ans[i] = w[i];
		if((i+bb)<N)
			ans[i] += ans[i+bb];
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&w[i]);
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		a[i]--;
		qid[i] = i;
	}
	sort(qid,qid+Q,cmp);
	int pre = b[qid[0]];
	long long bb;
	long long tot;
	for(int i=0;i<Q;i++)
	{
		bb = b[qid[i]];
		if((bb*bb <= N)&&((i==0)||(bb!=b[qid[i-1]])))
			calc(bb);
		if(bb*bb > N)
		{
			tot = 0;
			for(int j=a[qid[i]];j<N;j+=bb)
				tot += w[j];
			qans[qid[i]] = tot;
		}
		else
			qans[qid[i]] = ans[a[qid[i]]];
	}
	for(int i=0;i<Q;i++)
		printf("%I64d\n",qans[i]);
	return 0;
}