#include <iostream>
#include <cstdio>
using namespace std;

#define SEG (1<<20)
int seg[2*SEG],l[2*SEG],r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		seg[i] = 0;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = 0;
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

void update(int i,int v)
{
	i += SEG;
	seg[i] = v;
	for(i/=2;i>0;i/=2)
		seg[i] = max(seg[2*i],seg[2*i+1]);
}

int low,high;
int getMax(int i)
{
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return max(getMax(2*i),getMax(2*i+1));
}

int loc[1000000];
int A[1000000];
int dp[1000000];

int main()
{
	int N,a;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a);
		loc[a-1] = i;
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a);
		A[i] = loc[a-1];
	}
	init();
	int best = 0;
	for(int i=0;i<N;i++)
	{
		low = A[i];
		high = N-1;
		dp[i] = 1+getMax(1);
		update(A[i],dp[i]);
		if(dp[i]>best)
			best = dp[i];
	}
	printf("%d\n",best);
	return 0;
}