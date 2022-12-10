//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 10;
pii vec[100];
int s[maxn],
	n, siz, prv;
vector<int> arr;

int rate(int x) {
	return 32 - __builtin_clz(x);
}

bool cmp(int x, int y) {
	return rate(x) < rate(y);
}

void add(int x) {
	int val = x;
	for (int i = 0; i < siz; i++)
		if (x & (vec[i].L & -vec[i].L))
			x ^= vec[i].L;
	if (x == 0)
		return;
	for (int i = 0; i < siz; i++)
		if (vec[i].L & (x & -x))
			vec[i].L ^= x;
	vec[siz] = MP(x, val);
	siz++;
}

void expand(int val) {
	for (int i = sz(arr) - 1; i >= 0; i--)
		arr.PB(arr[i] ^ val);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	arr.PB(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) {
		int curr = rate(s[i]);
		add(s[i]);
		if (siz == curr) {
			for (int j = prv; j < siz; j++)
				expand(vec[j].R);
			prv = siz;
		}
	}
	cout << prv << '\n';
	for (auto val : arr)
		cout << val << ' ';
	cout << '\n';
	return 0;
}