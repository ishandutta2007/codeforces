#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int n, a, b, o[N], tot, p;
char s[N];
int rmain() {
	cin >> a >> b >> (s + 1), n = strlen(s + 1), tot = 0;
	int cnt = 0;
	L(i, 1, n) {
		if(s[i] == 'X' && cnt) o[++tot] = cnt, cnt = 0;
		else if(s[i] == '.') ++cnt;
	}
	if(cnt) o[++tot] = cnt;
	cnt = p = 0;
	L(i, 1, tot) if(o[i] >= 2 * b) cnt ++, p = o[i];
	if(cnt > 1) return cout << "NO\n", 0;
	cnt = 0;
	L(i, 1, tot) if(b <= o[i] && o[i] < a) return cout << "NO\n", 0;
	L(i, 1, tot) if(o[i] >= a) cnt ++;
	if(! p) return cout << (cnt % 2 ? "YES" : "NO") << "\n", 0;
	-- cnt, p -= a;
	if(cnt % 2 == 0) {
		if(0 <= p && p <= (b - 1) * 2) 
			return cout << "YES\n", 0;
		if(a * 2 <= p && p <= (2 * b - 1) * 2) 
			return cout << "YES\n", 0;
	}
	else {
//		cout << p << "\n";
//		cout << a + b - 1 << "\n";
		if(2 * b <= a) return cout << "NO\n", 0;
		if(a <= p && p <= 2 * b - 1 + b - 1) 
			return cout << "YES\n", 0;
	}
	cout << "NO\n";
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
}