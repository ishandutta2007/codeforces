#include <iostream>
#include <algorithm>
using namespace std;

long long req(long long k)
{
	if(k%2) return (k*(k-1))/2 + 1;
	else return (k*k)/2;
}

long long binSearch(long long low,long long high,long long n)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if(req(high)<=n) return high;
		return low;
	}
	long long mid = (low+high)/2;
	if(req(mid)<=n) return binSearch(mid,high,n);
	else return binSearch(low,mid-1,n);
}

long long v[100000];

int main()
{
	long long N,M;
	cin >> N >> M;
	long long a,b;
	for(long long i=0;i<M;i++)
	{
		cin >> a >> b;
		v[i] = b;
	}
	sort(v,v+M);
	long long mxNum = binSearch(1,M,N);
	long long ans = 0;
	for(long long i=0;i<mxNum;i++)
		ans += (long long)v[M-1-i];
	cout << ans << endl;
	return 0;
}