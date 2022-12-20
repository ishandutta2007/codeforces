#include <iostream>
using namespace std;

long long cnt1,cnt2,x,y;

bool pos(long long v)
{
	long long a1 = v-(v/x);
	long long a2 = v-(v/y);
	if((a1>=cnt1)&&(a2>=cnt2)&&((v-(v/(x*y)))>=(cnt1+cnt2)))
		return 1;
	return 0;
}

long long binSearch(long long low,long long high)
{
	if((low==high)) return low;
	if((low+1)==high)
	{
		if(pos(low)) return low;
		return high;
	}
	long long mid = (low+high)/2;
	if(pos(mid)) return binSearch(low,mid);
	return binSearch(mid+1,high);
}

int main()
{
	cin >> cnt1 >> cnt2 >> x >> y;
	cout << binSearch(1,1000000000000LL) << endl;
}