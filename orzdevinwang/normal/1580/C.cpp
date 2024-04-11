#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 6e5 + 7;
int n, m, B, now, x[N], y[N], cw[N];
int dt[N], sum, cnt[1000][1000];
void make (int i, int d, int det) {
	int all = x[i] + y[i];
	if((now - d) % all >= x[i]) 
		sum += det;
	if(all <= B) {
		cnt[all][(d + x[i]) % all] += det;
		cnt[all][d % all] -= det;
	}
	else {
		L(j, 0, (m + 1 - d) / all) { 
			dt[d + all * j + x[i]] += det;
			dt[d + all * j + x[i] + y[i]] -= det;
		}
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	B = sqrt (m);
	L(i, 1, n) {
		cin >> x[i] >> y[i];
		x[i] = min(x[i], m + 1);
		y[i] = min(y[i], m + 1);
	}
	L(i, 1, m) {
		now = i;
		int op, k;
		cin >> op >> k;
		sum += dt[i];
		L(p, 1, B) sum += cnt[p][i % p];
		if(op == 1) cw[k] = i, make(k, i, 1);
		else make (k, cw[k], -1); 
		cout << sum << "\n";
	}
	return 0;
}