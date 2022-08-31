#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 20);
int n, p[N], q[N], mp[N];

int sum[N], suf[N];
void add (int x, int L, int R, int p, int w) {
	if(L == R) 
		return sum[x] += w, suf[x] += w, void ();
	int mid = (L + R) >> 1;
	if(p <= mid) 
		add (x * 2, L, mid, p, w);
	else 
		add (x * 2 + 1, mid + 1, R, p, w);
	sum[x] = sum[x * 2] + sum[x * 2 + 1];
	suf[x] = max (suf[x * 2 + 1], suf[x * 2] + sum[x * 2 + 1]);
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> p[i], mp[p[i]] = i;
	L(i, 1, n) cin >> q[i];
	int h = n;
	add (1, 1, n, mp[n], 1);
	L(i, 1, n) {
		while (h > 1 && suf[1] <= 0) {
			h -= 1, add (1, 1, n, mp[h], 1); 
		}
		cout << h << " ";
		add (1, 1, n, q[i], -1);
	}
	return 0;
}