#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 2e6 + 7;
int n, m, nsa[N], nsb[N];
char s[N];
void Main () {
	cin >> n >> m, cin >> (s + 1);
	L(i, 1, (n + 1) * (m + 1)) nsa[i] = nsb[i] = 0;
	int pre = 0;
	L(i, 1, n * m) {
		pre += s[i] - '0';
		if(i > m) pre -= s[i - m] - '0';
		if(pre) nsa[i] += 1;
	}
	L(i, 1, n * m) nsa[i + m] += nsa[i];
	L(i, 1, m) {
		int ret = 0;
		L(j, 0, n - 1) {
			ret += s[i + j * m] - '0';
			if(ret) {
				nsb[i + j * m] += 1;
				nsb[i + (j + 1) * m] -= 1;
			}
		}
	}
	L(i, 1, n * m) nsb[i] += nsb[i - 1];
	L(i, 1, n * m) cout << nsa[i] + nsb[i] << ' ';
	cout << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}