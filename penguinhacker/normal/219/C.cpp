#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, k, cnt=0;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> s, s+=' ';
	if (k==2) {
		int numSame=0;
		for (int i=0; i<n; ++i) {
			char c='A'+(i&1);
			if (c==s[i])
				numSame++;
		}
		if (numSame>=(n+1)/2) {
			cnt=n-numSame;
			for (int i=0; i<n; ++i)
				s[i]=('A'+(i&1));
		}
		else {
			cnt=numSame;
			for (int i=0; i<n; ++i)
				s[i]=('A'+((i+1)&1));
		}
	}
	else {
		for (int i=1; i<n; ++i) {
			if (s[i]==s[i-1]) {
				for (int j=0; j<3; ++j) {
					if ('A'+j!=s[i-1]&&'A'+j!=s[i+1]) {
						s[i]='A'+j;
						break;
					}
				}
				cnt++;
			}
		}
	}
	s.pop_back();
	cout << cnt << '\n' << s;
	return 0;
}