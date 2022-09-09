#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long n, sum = 0;

long long a[23];
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a[x+10]++;
	}
	//
	for (int i = 1; i <= 10; i++)
		sum += a[10-i]*a[10+i];
	sum += a[10]*(a[10]-1)/2;
	cout << sum <<endl;
	//
	return 0;
}