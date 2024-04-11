#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define SEG (1<<17)
#define INF 1000000

int nRows,nCols;
int nRooks,Q;

int x[200000];
int y[200000];

int qx1[200000];
int qy1[200000];
int qx2[200000];
int qy2[200000];

int rid[200000];
int qid[200000];
int good[200000];

int seg[2*SEG];
int l[2*SEG];
int r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		seg[i] = -INF;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = -INF;
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

void update(int i,int v)
{
	i += SEG;
	seg[i] = v;
	for(i/=2;i>0;i/=2)
		seg[i] = min(seg[2*i],seg[2*i+1]);
}

int getMin(int i,int low,int high)
{
	if((r[i]<low)||(l[i]>high)) return INF;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return min(getMin(2*i,low,high),getMin(2*i+1,low,high));
}

bool rcmp(int a,int b)
{
	return x[a]<x[b];
}

bool qcmp(int a,int b)
{
	return qx2[a]<qx2[b];
}

void check()
{
	for(int i=0;i<nRooks;i++)
		rid[i] = i;
	for(int i=0;i<Q;i++)
		qid[i] = i;
	sort(rid,rid+nRooks,rcmp);
	sort(qid,qid+Q,qcmp);
	init();
	int ri = 0;
	int cur;
	for(int i=0;i<Q;i++)
	{
		cur = qid[i];
		while((ri<nRooks)&&(x[rid[ri]]<=qx2[cur]))
		{
			update(y[rid[ri]],x[rid[ri]]);
			ri++;
		}
		good[cur] += (getMin(1,qy1[cur],qy2[cur])>=qx1[cur]);
	}
}

int main()
{
	scanf("%d %d %d %d",&nRows,&nCols,&nRooks,&Q);
	for(int i=0;i<nRooks;i++)
		scanf("%d %d",&x[i],&y[i]);
	for(int i=0;i<Q;i++)
		scanf("%d %d %d %d",&qx1[i],&qy1[i],&qx2[i],&qy2[i]);
	for(int i=0;i<nRooks;i++)
		good[i] = 0;
	check();
	for(int i=0;i<nRooks;i++)
		swap(x[i],y[i]);
	for(int i=0;i<Q;i++)
	{
		swap(qx1[i],qy1[i]);
		swap(qx2[i],qy2[i]);
	}
	check();
	for(int i=0;i<Q;i++)
		printf((good[i])?"YES\n":"NO\n");
	return 0;
}