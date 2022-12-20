#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100011
long long T[MAXN];

long long getSum(int i)
{
	long long c=0;
	for(++i; i > 0 ; i -= (i & -i))
		c += T[i];
	return c;
}
void set(int i,long long dif)
{
	for(++i; i < MAXN ; i += (i & -i))
		T[i] += dif;
}

void init()
{
	for(int i=0;i<MAXN;i++)
		T[i] = 0;
}

void incRange(int i,int j,long long am)
{
	set(i,am);
	set(j+1,-am);
}

vector<long long> dif;

int N,M,W;
bool isPos(long long k)
{
	int i;
	long long reqDays = 0;
	init();
	for(i=0;i<=N;i++)
		set(i,dif[i]);
	for(i=0;i<N;i++)
	{
		long long cval = getSum(i);
		if(cval>=k)
			continue;
		int end = i+W-1;
		int start = i;
		if(end>=N)
		{
			end = N-1;
			start = end - (W-1);
		}
		incRange(start,end,k-cval);
		reqDays += k-cval;
	}
	return (reqDays<=M);
}

long long binSearch(long long low,long long high)
{
	if(low==high)
		return low;
	if(low==(high-1))
	{
		if(isPos(high))
			return high;
		return low;
	}
	long long mid = (low+high)/2;
	if(!isPos(mid))
		return binSearch(low,mid-1);
	else
		return binSearch(mid,high);
}

int main()
{
	vector<long long> A;
	cin >> N >> M >> W;
	int i,j;
	for(i=0;i<N;i++)
	{
		A.push_back(0);
		cin >> A[i];
	}
	dif.push_back(A[0]);
	for(i=1;i<N;i++)
		dif.push_back(A[i]-A[i-1]);
	dif.push_back(-A[N-1]);
	cout << binSearch((long long)1,(long long)1000000000+100000+1) << endl;
}