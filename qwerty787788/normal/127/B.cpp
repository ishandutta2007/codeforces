#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//
long long n, k;
vector <int> a;
int used[101];
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	for (int i = 0; i < n;i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	//
	sort(a.begin(), a.end());
	int sum = 0;
	for (int i=0 ; i < n-1; i++) {
		if (used[i] == 0) {
			if (a[i] == a[i+1]) {
				used[i+1] = 1;
				sum++;
			}
		}
	}
	sum /= 2;
	cout << sum << endl;
	//
	return 0;
}