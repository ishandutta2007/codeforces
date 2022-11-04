#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	long long a, b, i, sum;
	sum = 0;
	cin >> a >> b;
	for (i = 1; i <= a; i++)
		sum = (i*b + 1 + sum) % 1000000007;
	sum = (((b*(b - 1) / 2) % 1000000007)*(sum % 1000000007)) % 1000000007;
	cout << sum << endl;
	return 0;
}