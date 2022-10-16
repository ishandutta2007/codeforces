#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

void solve(int n)
{
	vector<int> mov = {1, 8, 2, 7, 3, 6, 4, 5};
	vector<string> ans;
	for (char c = 'a'; c <= 'f'; c++) {
		if (c == 'a' || c ==  'c' || c == 'e') {
			for (int i = 0; i < 8; i++) {
				string s;
				s.push_back(c);
				s += to_string(mov[i]);

				ans.push_back(s);
				if (ans.size() == n-1) {
					break;
				}
			}
			if (ans.size() == n-1) break;
		} else {
			for (int i = 7; i >= 0; i--) {
				string s;
				s.push_back(c);
				s += to_string(mov[i]);

				ans.push_back(s);
				if (ans.size() == n-1) {
					break;
				}
			}
			if (ans.size() == n-1) break;
		}
	}

	if (ans.size() == n-1) {
		char c = ans.back()[1];
		if (c != '8') {
			string s;
			s.push_back('h');
			s += c;

			ans.push_back(s);
			ans.push_back("h8");
		} else {
			string s;
			s.push_back('g');
			s += c;

			ans.push_back(s);
			ans.push_back("h8");
		}
		
	} else {
		for (int i = 0; i < 8; i++) {
			string s;
			s.push_back('g');
			s += to_string(mov[i]);

			ans.push_back(s);
			if (ans.size() == n-1) {
				break;
			}
		}
		if (n == 51) {
			ans.pop_back();
			ans.pop_back();
			ans.push_back("g1");
			ans.push_back("g2");
			ans.push_back("g8");
			ans.push_back("h8");
		} else if (ans.size() == n-1) {
			char c = ans.back()[1];
			string s;
			s.push_back('h');
			s += c;

			ans.push_back(s);
			ans.push_back("h8");
		} else {
			for (int i = 7; i >= 0; i--) {
				string s;
				s.push_back('h');
				s += to_string(mov[i]);

				ans.push_back(s);
				if (ans.size() == n+1) {
					ans.pop_back();
					if (ans.back() == "h8") {
						ans.pop_back();
						ans.push_back("h1");
					}
					ans.push_back("h8"); break;
				}
			}
		}
	}
	for (string s: ans) cout << s << ' '; cout << '\n';
}
signed main()
{
	//ios_base::sync_with_stdio(false), cin.tie(NULL);
	int testcase = 1;
	//cin >> testcase;
	while (testcase--)
	{
		int i; cin >> i;
		solve(i);
	}
	
}