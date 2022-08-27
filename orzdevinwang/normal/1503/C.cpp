#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 5e6 + 7;
int n, t[N];
struct node {
	int a, c;
} s[N];
ll ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> s[i].a >> s[i].c, ans += s[i].c;
	sort(s + 1, s + n + 1, [&] (node aa, node bb) {
		return aa.a < bb.a;
	});
	L(i, 1, n) {
		int l = i, r = n, ns = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(s[mid].a - s[i].a <= s[i].c) ns = mid, l = mid + 1;
			else r = mid - 1;
		}
		t[i] = ns;
	}
	int now = 1, mn = 1e9;
	L(i, 1, n) {
		if(now < i) ans += mn, mn = 1e9;
		if(t[i] > now) mn = s[t[i] + 1].a - s[i].a - s[i].c, now = t[i];
		else if(t[i] == now) mn = min(mn, s[t[i] + 1].a - s[i].a - s[i].c);
	}
	cout << ans <<"\n";
	return 0;
}