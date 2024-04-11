#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

#define pb push_back

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	n--;
	if (k >= n) {
		cout << n;
		return 0;
	}
	int cnt = 0;
	cnt += k;
	n -= k;
	int l = 2;
	while (n--) {
		cnt += l;
		l++;
	}
	cout << cnt;
}