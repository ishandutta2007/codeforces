//nathanajah's template
//25-10-2012
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#define LL long long
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

struct node
{
	int banyak[20];
	int lazy;
};

int n;
node stree[800000];
int arr[100005];
int i;
int q,q1,q2,q3,q4,q5;

void check(int a, int b, int now)
{
	if (a<b)
	{
		check(a,(a+b)/2,2*now+1);
		check((a+b)/2+1,b,2*now+2);
	}
	printf("==============\n");
	printf("%d %d %d\n",a,b,now);
	printf("%d\n",stree[now].lazy);
	int i;
	for (i=0;i<5;++i)
		printf("%d ",stree[now].banyak[i]);
	printf("\n");
}
void init(int a, int b, int now)
{
	int i;
	if (a==b)
	{
		for (i=0;i<20;++i)
			if ((arr[a] & (1<<i))!=0)
				++stree[now].banyak[i];
		stree[now].lazy=0;
	}
	else
	{
		init(a,(a+b)/2,2*now+1);
		init((a+b)/2+1,b,2*now+2);
		for (i=0;i<20;++i)
			stree[now].banyak[i]=stree[2*now+1].banyak[i]+stree[2*now+2].banyak[i];
		stree[now].lazy=0;
	}
}

void upd(int l, int r, int x, int a, int b, int now)
{
	int i;
	if (l==a && r==b)
		stree[now].lazy=stree[now].lazy^x;
	else
	{
		for (i=0;i<20;++i)
			if ((stree[now].lazy & (1<<i))!=0)
				stree[now].banyak[i]=b-a+1-stree[now].banyak[i];
		stree[2*now+1].lazy=stree[2*now+1].lazy^stree[now].lazy;
		stree[2*now+2].lazy=stree[2*now+2].lazy^stree[now].lazy;
		stree[now].lazy=0;
		if (r<=(a+b)/2)
		{
			upd(l,r,x,a,(a+b)/2,2*now+1);
		}
		else if (l>(a+b)/2)
		{
			upd(l,r,x,(a+b)/2+1,b,2*now+2);
		}
		else
		{
			upd(l,(a+b)/2,x,a,(a+b)/2,2*now+1);
			upd((a+b)/2+1,r,x,(a+b)/2+1,b,2*now+2);
		}
		for (i=0;i<20;++i)
			stree[now].banyak[i]=0;
		for (i=0;i<20;++i)
		{
			if ((stree[2*now+1].lazy & (1<<i))!=0)
				stree[now].banyak[i]+=((a+b)/2 - a + 1)- stree[2*now+1].banyak[i];
			else
				stree[now].banyak[i]+=stree[2*now+1].banyak[i];
		}
		for (i=0;i<20;++i)
		{
			if ((stree[2*now+2].lazy & (1<<i))!=0)
				stree[now].banyak[i]+=(b - (a+b)/2)- stree[2*now+2].banyak[i];
			else
				stree[now].banyak[i]+=stree[2*now+2].banyak[i];
		}
	}
}
LL get(int l, int r, int a, int b, int now)
{
	LL res=0;
	int i;
	if (l==a && r==b)
	{
		for (i=0;i<20;++i)
		{
			if ((stree[now].lazy & (1<<i))!=0)
				res+=(LL)(b-a+1-stree[now].banyak[i])*(LL)(1<<i);
			else
				res+=(LL)(stree[now].banyak[i])*(LL)(1<<i);
		}
		return res;
	}
	else
	{
		for (i=0;i<20;++i)
			if ((stree[now].lazy & (1<<i))!=0)
				stree[now].banyak[i]=b-a+1-stree[now].banyak[i];
		stree[2*now+1].lazy=stree[2*now+1].lazy^stree[now].lazy;
		stree[2*now+2].lazy=stree[2*now+2].lazy^stree[now].lazy;
		stree[now].lazy=0;
		if (r<=(a+b)/2)
			return get(l,r,a,(a+b)/2,2*now+1);
		else if (l>(a+b)/2)
			return get(l,r,(a+b)/2+1,b,2*now+2);
		else
			return get(l,(a+b)/2,a,(a+b)/2,2*now+1)+get((a+b)/2+1,r,(a+b)/2+1,b,2*now+2);
	}
}
int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i)
		scanf("%d",&arr[i]);
	init(0,n-1,0);
//	check(0,n-1,0);
	scanf("%d",&q);
	for (i=0;i<q;++i)
	{
		scanf("%d",&q1);
		if (q1==1)
		{
			scanf("%d %d",&q2,&q3);
			--q2;--q3;
			printf("%I64d\n",get(q2,q3,0,n-1,0));
		}
		else
		{
			scanf("%d %d %d",&q2,&q3,&q4);
			--q2;--q3;
			upd(q2,q3,q4,0,n-1,0);
//			check(0,n-1,0);
		}
	}
}