#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long x[1000], y[1000], result;
long long max(long long a,long long b)
{
	if (a > b)return a;
	else return b;
}
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i <= n - 1; i++){
		cin >> x[i] >> y[i];
	}
	sort(x, x + n);
	sort(y, y + n);
	result = max(x[n - 1] - x[0], y[n - 1] - y[0]);
	result = result*result;
	cout << result << endl;
	return 0;
}