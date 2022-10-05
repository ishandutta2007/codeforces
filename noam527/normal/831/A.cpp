#include <iostream>
#define done cout << "YES" << endl; return 0
#define done2 cout << "NO" << endl; return 0
using namespace std;

int main() {
	int n, a[100], j = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	while (j + 1 < n && a[j + 1] > a[j]) j++;
	if (j + 1 == n) { done; }
	while (j + 1 < n && a[j + 1] == a[j]) j++;
	if (j + 1 == n) { done; }
	if (a[j + 1] > a[j]) { done2; }
	while (j + 1 < n && a[j + 1] < a[j]) j++;
	if (j + 1 == n) { done; }
	done2;
}