#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if (2 * (a[0] + a[1]) <= a[2])cout << a[0] + a[1] << endl;
	else cout << (a[0] + a[1] + a[2]) / 3 << endl;
	return 0;
}