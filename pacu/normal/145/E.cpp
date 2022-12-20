#include <cstdio>
#include <iostream>
using namespace std;
#define SEG (1<<20)

char s[1000001];
int A[1000000];
int N;

int s0[2*SEG],s1[2*SEG],s10[2*SEG],s01[2*SEG],l[2*SEG],r[2*SEG],up[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		if((i-SEG)<N)
		{
			s0[i] = (A[i-SEG]==0);
			s1[i] = (A[i-SEG]==1);
			s10[i] = s01[i] = 1;
		}
		else
			s0[i] = s1[i] = s10[i] = s01[i] = 0;
		l[i] = r[i] = i-SEG;
		up[i] = 0;
	}
	for(int i=SEG-1;i>0;i--)
	{
		s0[i] = s0[i<<1] + s0[(i<<1)+1];
		s1[i] = s1[i<<1] + s1[(i<<1)+1];
		s10[i] = max(s10[i<<1]+s0[(i<<1)+1],s1[i<<1]+s10[(i<<1)+1]);
		s01[i] = max(s01[i<<1]+s1[(i<<1)+1],s0[i<<1]+s01[(i<<1)+1]);
		l[i] = l[i<<1];
		r[i] = r[(i<<1)+1];
		up[i] = 0;
	}

}

void push(int i)
{
	if(up[i])
	{
		if(i<SEG)
		{
			up[i<<1] ^= 1;
			up[(i<<1)+1] ^= 1;
		}
		swap(s0[i],s1[i]);
		swap(s10[i],s01[i]);
		up[i] = 0;
	}
}

int low,high;
void update(int i)
{
	push(i);
	if((l[i]>high)||(r[i]<low)) return;
	if((l[i]>=low)&&(r[i]<=high))
	{
		up[i] ^= 1;
		push(i);
		return;
	}
	update(i<<1);
	update((i<<1)+1);
	s0[i] = s0[i<<1] + s0[(i<<1)+1];
	s1[i] = s1[i<<1] + s1[(i<<1)+1];
	s10[i] = max(s10[i<<1]+s0[(i<<1)+1],s1[i<<1]+s10[(i<<1)+1]);
	s01[i] = max(s01[i<<1]+s1[(i<<1)+1],s0[i<<1]+s01[(i<<1)+1]);
}

char in[10];

void sw(int a,int b)
{
	for(int i=a;i<=b;i++)
		A[i] ^= 1;
}

int cnt()
{
	int c0 = 0;
	int c1 = 0;
	for(int i=0;i<N;i++)
	{
		if(A[i] == 0) c0++;
		else c1++;
		c1 = max(c1,c0);
	}
	return c1;
}

int main()
{
	int Q;
	scanf("%d %d",&N,&Q);
//	N = 10000;
//	Q = 0;
	scanf("%s",s);
	for(int i=0;i<N;i++)
		A[i] = (s[i]=='7');
//		A[i] = 0;
	init();
	int a,b;
	for(int i=0;i<Q;i++)
	{
//		if(!(i%500)) printf("%d\n",i);
		scanf("%s",in);
		if(in[0]=='c')
//		if(i%2)
		{
			push(1);
			printf("%d\n",s01[1]);
//			if(s01[1] != cnt())
//				printf("%d %d\n",s01[1],cnt());
		}
		else
		{
			scanf("%d %d",&low,&high);
//			low = rand()%N;
//			high = rand()%N;
//			if(low>high) swap(low,high);
			low--,high--;
			update(1);
//			sw(low,high);
		}
	}
}