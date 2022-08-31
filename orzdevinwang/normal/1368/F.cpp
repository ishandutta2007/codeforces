#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 5005;
int n, B, cB, k, a[N], s[N], tot;
bool used[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, B = sqrt(n), cB = (n - 1) / B + 1;
	int o = 0;
	L(i, 1, cB) o += n / cB + (n % cB >= i), used[o] = 1;
	while(1) {
		tot = 0;
		L(i, 1, n) if((!a[i]) && (!used[i])) s[++tot] = i;
		if(tot < B) break;
		tot = min(tot, B), cout << B << " ";
		L(i, 1, tot) cout << s[i] << " ", a[s[i]] = true;
		cout << endl, fflush(stdout), cin >> k;
		L(i, 1, B) a[k] = false, k = k % n + 1;
	}
	cout << "0" << endl;
	return 0;
}