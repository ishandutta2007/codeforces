#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	long long m, n, kmin, kmax, count;
	cin >> n >> m;
	kmax = (n - m + 1)*(n - m) / 2;
	count = n - m*(n / m);
	kmin = count*((n / m) + 1)*(n / m) / 2 + (m - count)*(n / m)*((n / m) - 1) / 2;
	cout << kmin;
	printf(" ");
	cout << kmax << endl;
	return 0;
}