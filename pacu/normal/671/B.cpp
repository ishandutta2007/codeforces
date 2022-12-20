#include <iostream>
using namespace std;

int N,K;
int A[500000];

bool posRedHigh(int v)
{
	long long c = 0;
	for(int i=0;i<N;i++)
		if(A[i]>v)
			c += A[i]-v;
	return c <= K;
}

int redHigh(int low,int high)
{
	if(low==high) return low;
	if(low==high-1)
	{
		if(posRedHigh(low)) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(posRedHigh(mid)) return redHigh(low,mid);
	else return redHigh(mid+1,high);
}

bool posIncLow(int v)
{
	long long c = 0;
	for(int i=0;i<N;i++)
		if(A[i]<v)
			c += v-A[i];
	return c <= K;
}

int incLow(int low,int high)
{
	if(low==high) return low;
	if(low==high-1)
	{
		if(posIncLow(high)) return high;
		return low;
	}
	int mid = (low+high)/2;
	if(posIncLow(mid)) return incLow(mid,high);
	else return incLow(low,mid-1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	for(int i=0;i<N;i++) cin >> A[i];
	int low = incLow(1,1000000000);
	int high = redHigh(1,1000000000);
	if(high <= low)
	{
		long long tot = 0;
		for(int i=0;i<N;i++)
			tot += A[i];
		if(tot%N == 0) cout << 0 << '\n';
		else cout << 1 << '\n';
		return 0;
	}
	cout << high-low << '\n';
}