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
const int N = 4e5 + 7;
int n, m, A[N], B[N];
ll ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> A[i] >> B[i];
	sort(A + 1, A + n + 1);
	sort(B + 1, B + n + 1);
	L(i, 1, n) ans += max(A[i], B[i]);
	cout << ans + n << endl;
	return 0;
}