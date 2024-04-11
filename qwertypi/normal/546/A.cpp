#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int cnt[5];
int main(){
	long long k, n, w;
	cin >> k >> n >> w;
	cout << max(0LL, k * w * (w + 1) / 2 - n);
	return 0;
}