#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 207;
int n, m, s[N][N], sum[N];
void Main() {
	cin >> n >> m;
	L(i, 2, n + m) sum[i] = 0;
	L(i, 1, n) L(j, 1, m) cin >> s[i][j], sum[i + j] ^= s[i][j];
	L(i, 2, n + m) if(sum[i]) return cout << "Ashish\n", void();
	cout << "Jeel\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}