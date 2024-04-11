#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
#define SEG (1<<17)
#define INF 2000000000

int seg[2*SEG];
int l[2*SEG];
int r[2*SEG];
int inc[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		seg[i] = -INF;
		l[i] = r[i] = i-SEG;
		inc[i] = -INF;
	}
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = -INF;
		l[i] = l[2*i];
		r[i] = r[2*i+1];
		inc[i] = -INF;
	}
}

void push(int i)
{
	seg[i] = max(seg[i],inc[i]);
	inc[2*i] = max(inc[2*i],inc[i]);
	inc[2*i+1] = max(inc[2*i+1],inc[i]);
	inc[i] = -INF;
}

int update(int i,int low,int high,int v)
{
	if((r[i]<low)||(l[i]>high)) return -INF;
	if((l[i]>=low)&&(r[i]<=high))
	{
		inc[i] = max(inc[i],v);
		seg[i] = max(seg[i],inc[i]);
		return seg[i];
	}
	push(i);
	seg[i] = max(seg[i],update(2*i,low,high,v));
	seg[i] = max(seg[i],update(2*i+1,low,high,v));
	//seg[i] = max(max(seg[2*i],seg[2*i+1]),max(inc[2*i],inc[2*i+1]));
	return seg[i];
}


int getMax(int loc)
{
	loc += SEG;
	for(int i=1;;i*=2)
	{
		if(r[i]<(loc-SEG))
			i++;
		if(i==loc)
			break;
		push(i);
	}
	return max(seg[loc],inc[loc]);
}


int A[100000];
int bl[100000];
int bh[100000];
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	init();
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	unordered_map<int,int> M;
	for(int i=0;i<N;i++)
	{
		if(M.find(A[i])==M.end())
			bl[i] = max(-1,i-K);
		else
			bl[i] = max(M[A[i]],i-K);
		M[A[i]] = i;
	}
	M.clear();
	for(int i=N-1;i>=0;i--)
	{
		if(M.find(A[i])==M.end())
			bh[i] = min(N,i+K);
		else
			bh[i] = min(M[A[i]],i+K);
		M[A[i]] = i;
	}
	for(int i=0;i<N;i++)
		if((bl[i]+1)<=(bh[i]-K))
			update(1,bl[i]+1,bh[i]-K,A[i]);
	int ans;
	for(int i=0;i<=(N-K);i++)
	{
		ans = getMax(i);
		if(ans == -INF)
			printf("Nothing\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}