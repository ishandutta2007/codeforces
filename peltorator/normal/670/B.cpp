#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;



int main()
{
	int n, k;
	cin >> n >> k;
	vector < int > a(n);
	for (int i = 0; i < n; i++) cin >> a[i];


	for (int i = 0; i < n; i++)
	{
		if (k > i) k -= i;
		else i = n + 5;
	}
	cout << a[k-1];
	return 0;
}