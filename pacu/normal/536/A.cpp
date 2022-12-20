#include <iostream>
#include <algorithm>
using namespace std;

long long cval[100001];
long long sm[100002];
long long A,B,N;
long long l,t,m;

long long s(long long i)
{
	return i*A + ((i*(i-1))/2)*B;
}

long long top(long long i)
{
	return A+(i-1)*B;
}

long long binSearch(long long low,long long high,long long x)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if((s(high)<=x)&&(top(high)<=t)) return high;
		return low;
	}
	long long mid = (low+high)/2;
	if((s(mid)>x)||(top(mid)>t)) return binSearch(low,mid-1,x);
	else return binSearch(mid,high,x);
}

int main()
{
	cin >> A >> B >> N;
	long long sval;
	for(int i=0;i<N;i++)
	{
		cin >> l >> t >> m;
		sval = t*m+s(l-1);
		long long x = binSearch(0,1000000000,sval);
		if(x<l) cout << "-1\n";
		else cout << x << "\n";
	}
}