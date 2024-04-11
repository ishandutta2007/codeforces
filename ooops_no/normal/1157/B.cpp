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
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(9);
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
	}
	int i = 0;
	while (i < s.length() &&  v[s[i] - '0' - 1] <= s[i] - '0') {
		i++;
	}
	if (i == s.length()) {
		cout << s;
		return 0;
	}
	s[i] = v[s[i] - '0' - 1] + '0';
	for (int j = i + 1; j < s.length(); j++) {
		if (v[s[j] - '0' - 1] >= s[j] - '0') {
			s[j] = v[s[j] - '0' - 1] + '0';
		}
		else {
			break;
		}
	}
	cout << s;
}