#include <iostream>
using namespace std;

#define MAXN 200005
int T[MAXN+1];

int getSum(int i)
{
	if(i==-1) return 0;
	int c=0;
	for(++i; i > 0 ; i -= (i & -i))
		c += T[i];
	return c;
}
void set(int i,int dif)
{
	for(++i; i < MAXN ; i += (i & -i))
		T[i] += dif;
}
void init()
{
	for(int i=0;i<MAXN;i++)
		T[i] = 0;
}

int A[200000];
int B[200000];
int C[200000];
int redA[200000];
int redB[200000];
int redC[200000];

int binSearch(int low,int high,int val)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if(getSum(high)==val) return high;
		return low;
	}
	int mid = (low+high)/2;
	if(getSum(mid)>val) return binSearch(low,mid-1,val);
	else return binSearch(mid,high,val);
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int j=0;j<N;j++)
		cin >> B[j];
	if(N==1)
	{
		cout << 0 << endl;
		return 0;
	}
	init();
	for(int i=0;i<N;i++)
	{
		redA[i] = A[i] - getSum(A[i]);
		set(A[i],+1);
	}
	init();
	for(int i=0;i<N;i++)
	{
		redB[i] = B[i] - getSum(B[i]);
		set(B[i],+1);
	}
	int carry = 0;
	for(int i=(N-1);i>=0;i--)
	{
		redC[i] = redA[i]+redB[i]+carry;
		carry = redC[i]/(N-i);
		redC[i] %= (N-i);
	}
	init();
	for(int i=0;i<=N;i++)
		set(i,+1);
	for(int i=0;i<N;i++)
	{
		C[i] = binSearch(-1,N,redC[i])+1;
		set(C[i],-1);
	}
	for(int i=0;i<N;i++)
		cout << C[i] << " ";
	return 0;
}