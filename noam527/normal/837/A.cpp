#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
using namespace std;

int n, mx = -1, cnt = 0;
string s, s2;

int main() {
	fast;
	cin >> n;
	while (s.size() < n)
		cin >> s2, s.append(s2), s.push_back(' ');
	for (auto c : s) {
		if (c == ' ')
			mx = max(mx, cnt), cnt = 0;
		else if (c >= 'A' && c <= 'Z') cnt++;
	}
	mx = max(mx, cnt);
	cout << mx << endl;
}