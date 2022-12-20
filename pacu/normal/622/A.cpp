#include <iostream>
using namespace std;

long long binSearch(long long low,long long high,long long n)
{
	if(low==high) return (low*(low+1))/2;
	if(low+1==high)
	{
		if((high*(high+1))/2 < n) return (high*(high+1))/2;
		return (low*(low+1))/2;
	}
	long long mid = (low+high)/2;
	if((mid*(mid+1))/2 < n) return binSearch(mid,high,n);
	else return binSearch(low,mid-1,n);
}

int main()
{
	long long n;
	cin >> n;
	cout << n-binSearch(0,100000000,n) << '\n';
}