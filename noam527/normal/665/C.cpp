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

string s;

char ne(char a, char b) {
	if (a != 'a' && b != 'a') return 'a';
	if (a != 'b' && b != 'b') return 'b';
	return 'c';
}

int main() {
	fast;
	cin >> s;
	for (int i = 1; i < s.size() - 1; i++)
		if (s[i] == s[i - 1]) s[i] = ne(s[i - 1], s[i + 1]);
	if (last(s, 1) == last(s, 2)) last(s, 1) = ne(last(s, 1), 'z');
	cout << s << endl;
}