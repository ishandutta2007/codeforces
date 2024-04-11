#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>
#include <numeric> 

#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int cnt = 0;
	if (a != b) {
		cnt++;
	}
	cout << min(b + c, a + c) * 2 + cnt;
}