#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define INF (1<<30)
#define SEG (1<<19)
#define DEBUG 0

int seg[2*SEG];
int l[2*SEG];
int r[2*SEG];

void init()
{
	for(int i=0;i<2*SEG;i++)
		seg[i] = INF;
	for(int i=SEG;i<2*SEG;i++)
		l[i] = r[i] = i-SEG;
	for(int i=(SEG-1);i>=0;i--)
	{
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

void update(int i,int v)
{
	i += SEG;
	seg[i] = v;
	i >>= 1;
	while(i>0)
	{
		seg[i] = min(seg[i<<1],seg[(i<<1)+1]);
		i>>=1;
	}
}

int low,high;
int getMin(int i)
{
	if((r[i]<low)||(l[i]>high)) return INF;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return min(getMin(i<<1),getMin((i<<1)+1));
}

int N,Q;
int A[500000];
int nxt[500000];
unordered_map<int,int> M;
int aid[500000];
int Ql[500000];
int Qr[500000];
int ans[500000];
int qid[500000];

bool cmp(int a,int b)
{
	return nxt[a]<nxt[b];
}

bool cmpq(int a,int b)
{
	return Qr[a]<Qr[b];
}

int main()
{
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	for(int i=(N-1);i>=0;i--)
	{
		if(M.count(A[i]) == 0) nxt[i] = INF;
		else nxt[i] = M[A[i]];
		M[A[i]] = i;
	}
#if DEBUG
	for(int i=0;i<N;i++)
		printf("%d ",nxt[i]);
	printf("\n");
#endif

	for(int i=0;i<N;i++)
		aid[i] = i;
	sort(aid,aid+N,cmp);

#if DEBUG
	for(int i=0;i<N;i++)
		printf("%d ",aid[i]);
	printf("\n");
#endif

	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&Ql[i],&Qr[i]);
		Ql[i]--,Qr[i]--;
	}
	for(int i=0;i<Q;i++)
		qid[i] = i;
	sort(qid,qid+Q,cmpq);

	int curq;
	int j = 0;
	init();
	for(int i=0;i<Q;i++)
	{
		curq = qid[i];
		while((j<N)&&(nxt[aid[j]]<=Qr[curq]))
		{
			update(aid[j],nxt[aid[j]]-aid[j]);
			j++;
		}
		low = Ql[curq];
		high = Qr[curq];
		ans[curq] = getMin(1);
		if(ans[curq]==INF) ans[curq] = -1;
	}
	for(int i=0;i<Q;i++)
		printf("%d\n",ans[i]);
	return 0;
}