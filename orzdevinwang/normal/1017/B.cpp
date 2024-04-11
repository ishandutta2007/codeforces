#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, m, cnta, cntb, cntc;
char a[N], b[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> (a + 1) >> (b + 1);
	L(i, 1, n) {
		cnta += (a[i] == '1');
		cntb += (b[i] == '1' && a[i] == '1');
		cntc += (b[i] == '1' && a[i] == '0');
	}
	cout << (ll) cnta * (n - cnta) - (ll) cntb * cntc;
	return 0;
}