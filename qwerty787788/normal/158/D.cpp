#include <map>
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
#include <cstdio>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
int n;
int sum = -1e9;
int a[20000];
//
int main() {
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
	}
	for (int k = 1; k <= (n / 3); k++) 
		if (n % k == 0 && (n / k > 2)) 
			for (int st = 0; st < k; st++) {
				int s1 = 0;
				int x = st;
				while (x < n) {
					s1 += a[x];
					x += k;
				}
				if (s1 > sum) sum = s1;
			}
	cout << sum << endl;
}