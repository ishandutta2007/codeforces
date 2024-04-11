#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
long long n, sum;
long long a[5001];

//
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        cin >> n;
		long long x;
		//
		for (int i = 0; i < n;i ++) {
			cin >> x;
			a[x] = 1;
		}
		//
		for (int i = 1; i <= n; i++)
			if (a[i] == 0) sum++;
		//
        cout << sum;
}