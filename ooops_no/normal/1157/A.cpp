#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define mp make_pair

signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int n, m = 0;
	cin >> n; 
	set<int> s;
	s.insert(n);
	while (true) {
		m = s.size();
		n++;
		while (n % 10 == 0 && n > 0) {
			n /= 10;
		}
		s.insert(n);
		if (m == s.size()) {
			break;
		}
	}
	cout << m;
}