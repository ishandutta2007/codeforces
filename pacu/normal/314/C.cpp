#include <iostream>
using namespace std;

#define MAXN 1000010
long long T[MAXN];

void init()
{
	for(int i=0;i<MAXN;i++)
		T[i] = 0;
}

void set(int i,long long d)
{
	for(i++;i<MAXN;i+=(i&-i))
		T[i] = (T[i]+d)%1000000007;
}

long long getSum(int i)
{
	long long c = 0;
	for(i++;i>0;i-=(i&-i))
		c = (c+T[i])%1000000007;
	return c;
}

int A[100000];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	long long x,y;
	for(int i=0;i<N;i++)
	{
		y = getSum(A[i])-getSum(A[i]-1);
		x = (A[i]*(getSum(A[i])+1))%1000000007;
		set(A[i],x-y);
	}
	cout << getSum(1000000) << endl;
	return 0;
}