#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
typedef long long ll;
typedef double db;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	ll n, k, d;
	cin >> n >> k;
	d = n / 2 / (k + 1);
	cout << d << " " << k * d << " " << n - (k + 1) * d << endl;
}