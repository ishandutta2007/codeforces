#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n;
struct node {
	int a, t;
} s[N];
ll ret = 0;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> s[i].a;
	}
	L(i, 1, n) {
		cin >> s[i].t;
	}
	sort (s + 1, s + n + 1, [&] (node a, node b) {
		return a.a < b.a;
	});
	s[n + 1].a = 2e9;
	multiset < int > st;
	ll ns = 0;
	L(i, 1, n) {
		st.insert(s[i].t);
		ret += s[i].t;
		for (int j = s[i].a; sz(st) && j < s[i + 1].a; j++) {
			ret -= *--st.end();
			st.erase(--st.end());
			ns += ret;
		}
	}
	cout << ns << '\n';
	return 0;
}