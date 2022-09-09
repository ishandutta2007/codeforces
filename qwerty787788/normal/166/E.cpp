#include <map>
#include <set>
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
long long w1, w2, w3, w4;
//
int main() {
	//freopen("Input.txt", "r", stdin);
	//freopen("Output.txt", "w", stdout);
	//
	cin >> n;
	w1 = 1; w2 = 0; w3 = 0; w4 = 0;
	long long mod = 1e9 + 7;
	while (n > 0) {
		n--;
		long w1n = (w2 + w3 + w4)%mod;
		long w2n = (w1 + w3 + w4)%mod;
		long w3n = (w2 + w1 + w4)%mod;
		long w4n = (w2 + w3 + w1)%mod;
		w1 = w1n; w2 = w2n; w3 = w3n; w4 = w4n;
	}
	cout << w1 << endl;
}