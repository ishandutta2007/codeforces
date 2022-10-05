#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, a[101], sum = 0, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	cout << max(0, (n * k - sum) * 2 - n) << endl;
}