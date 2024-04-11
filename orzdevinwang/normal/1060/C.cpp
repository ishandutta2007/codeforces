#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
#define vei vector<int>
using namespace std;
const int N = 2005;
const int M = N * N;
int n, m, tot, Ans;
ll A[N], B[N], x;
struct node {
	ll val; int x;
} f[M];
ll k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> A[i], A[i] += A[i - 1];
	L(i, 1, m) cin >> B[i], B[i] += B[i - 1];
	cin >> k;
	L(i, 1, m) L(j, i, m) ++tot, f[tot].val = B[j] - B[i - 1], f[tot].x = j - i + 1;
	sort(f + 1, f + tot + 1, [&](node aa, node bb) { return aa.val < bb.val; });
	L(i, 1, tot) f[i].x = max(f[i].x, f[i - 1].x);
	L(i, 1, n) L(j, i, n) {
		ll dd = A[j] - A[i - 1];
		int l = 1, r = tot, ans = 0;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(f[mid].val * dd <= k) ans = f[mid].x, l = mid + 1;
			else r = mid - 1;
		}
		Ans = max(Ans, (j - i + 1) * ans);
	}
	cout << Ans << endl;
	return 0;
}