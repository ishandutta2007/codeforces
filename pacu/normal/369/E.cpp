#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define SEG (1<<20)

int seg[2*SEG];
int l[2*SEG];
int r[2*SEG];

void init()
{
	for(int i=1;i<2*SEG;i++)
	{
		seg[i] = 0;
		l[i] = r[i] = i-SEG;
	}
	for(int i=(SEG-1);i>0;i--)
	{
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

void update(int s)
{
	s += SEG;
	seg[s]++;
	s /= 2;
	while(s>0)
	{
		seg[s] = seg[2*s]+seg[2*s+1];
		s /= 2;
	}
}

int getSum(int i,int low,int high)
{
	if((r[i]<low)||(l[i]>high)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return getSum(2*i,low,high)+getSum(2*i+1,low,high);
}


int qSize[300000];

int qx[900000];
int qStart[600000];
int qEnd[600000];
int qAns[600000];
int qid[600000];

int pStart[300000];
int pEnd[300000];
int pid[300000];
int N,Q;

bool qCmpEnd(int a,int b)
{
	return qEnd[a]<qEnd[b];
}
bool pCmpEnd(int a,int b)
{
	return pEnd[a]<pEnd[b];
}

int main()
{
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)
	{
		cin >> pStart[i] >> pEnd[i];
		pid[i] = i;
	}
	int cur = 0;
	int qPairs = 0;
	for(int i=0;i<Q;i++)
	{
		scanf("%d",&qSize[i]);
		qx[cur++] = 0;
		for(int j=0;j<qSize[i];j++)
		{
			scanf("%d",&qx[cur++]);
			qStart[qPairs] = qx[cur-2];
			qEnd[qPairs] = qx[cur-1];
			qid[qPairs] = qPairs;
			qPairs++;
		}
		qx[cur++] = 1000001;
		qStart[qPairs] = qx[cur-2];
		qEnd[qPairs] = qx[cur-1];
		qid[qPairs] = qPairs;
		qPairs++;
	}
	sort(pid,pid+N,pCmpEnd);
	sort(qid,qid+qPairs,qCmpEnd);
	int qCur;
	int j = 0;
	init();
	for(int i=0;i<qPairs;i++)
	{
		qCur = qid[i];
		while((j<N) && (pEnd[pid[j]] < qEnd[qCur]))
		{
			update(pStart[pid[j]]);
			j++;
		}
		qAns[qCur] = j-getSum(1,0,qStart[qCur]);
	}
	int ans;
	cur = 0;
	for(int i=0;i<Q;i++)
	{
		ans = N;
		for(int j=0;j<(1+qSize[i]);j++)
			ans -= qAns[cur++];
		printf("%d\n",ans);
	}
	return 0;
}