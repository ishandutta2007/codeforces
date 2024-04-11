#include <iostream>
using namespace std;

#define MAXN 5010
int T[MAXN];
void init()
{
	for(int i=0;i<MAXN;i++)
		T[i] = 0;
}
void set(int i,int d)
{
	for(i++;i<MAXN;i+=(i&-i))
		T[i] += d;
}
int getSum(int i)
{
	int c = 0;
	for(i++;i>0;i-=(i&-i))
		c += T[i];
	return c;
}

int A[5000];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int best = 0;
	int num = 0;
	int cur;
	int low = N+1;
	for(int i=N-1;i>0;i--)
	{
//		if(A[i] > low)
//			continue;
		low = A[i];
		init();
		for(int j=i-1;j>=0;j--)
		{
			if(A[j]>A[i])
			{
				cur = getSum(A[j]);
				set(A[j],1);
				if(best==cur)
					num++;
				if(best<cur)
				{
					best = cur;
					num = 1;
				}
			}
		}
	}
	init();
	int old = 0;
	for(int i=N-1;i>=0;i--)
	{
		old += getSum(A[i]);
		set(A[i],1);
	}
	cout << old-2*best-1 << " " << num << endl;
}