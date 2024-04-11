#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200000;
int n; //dp[mxN][2];
string s;
void test_case() {
	cin >> n >> s;
	int cnt=0;
	int ans=0;
	if (count(s.begin(), s.end(), 'L')==0||count(s.begin(), s.end(), 'R')==0) {
		++ans;
		s[0]=s[0]=='L'?'R':'L';
	}
	while(s.size()>1&&s.back()==s[0]) {
		++cnt;
		s.pop_back();
	}
	string temp(cnt, s[0]);
	s=temp+s;
	//cout << s << '\n';
	pair<int, char> last={-1, 'P'};
	for (char c: s) {
		if (c==last.second)
			++last.first;
		else {
			ans+=last.first/3;
			last={1, c};
		}
	}
	ans+=last.first/3;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/