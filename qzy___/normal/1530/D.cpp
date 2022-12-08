#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

int T, n, a[N], c[N], ans;
int in[N], out[N];

int t[N];

bool get() {
	for (int i = 1; i <= n; i++)
		in[i] = out[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			out[i]++, in[a[i]]++;
		}
	}
	if (ans == n - 1) {
		int flag1 = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i]) {
				if (!(in[i] == 1 && out[i] == 1))
					flag1 = 0;
			}
		}
		if (flag1) return false;
	}
	vector <int> vin, vout, emp;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0 && out[i] == 0) {
			emp.push_back(i);
			continue;
		}
		if (in[i] == 0) vin.push_back(i);
		if (out[i] == 0) vout.push_back(i);
	}
	if (emp.size()) {
		for (int i = 0; i < (int)emp.size() - 1; i++)
			a[emp[i]] = emp[i + 1];
		vin.push_back(emp[0]), vout.push_back(emp[emp.size() - 1]);
	}
	reverse(vout.begin(), vout.end());
	for (int i = 0; i < vin.size(); i++)
		a[vout[i]] = vin[i];
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> n; ans = n;
		for (int i = 1; i <= n; i++)
			c[i] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (c[a[i]]) ans--;
			c[a[i]]++;
		}
		if (ans == n - 1) {
			for (int i = 1; i <= n; i++) {
				if (c[a[i]] > 1) {
					int temp = a[i];
					a[i] = 0;
					if (get()) break;
					a[i] = temp;
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				c[i] = 0;
			}
			for (int i = 1; i <= n; i++) {
				if (c[a[i]] > 0) a[i] = 0;
				else  c[a[i]]++;
			}
			get();
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}