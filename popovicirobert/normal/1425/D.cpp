#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = 2000;
const int MAXC = 1000;

int fact[MAXN + 1];
//int invfact[MAXN + 1];

int comb[MAXN + 1][MAXN + 1];
//int aran[MAXN + 1][MAXN + 1];

//int danger[MAXC + 1][MAXC + 1];
int counter[MAXC + 1][MAXC + 1];

inline void add(int& x, int y) {
	x += y;
	if(x >= MOD)
		x -= MOD;
}

inline void sub(int& x, int y) {
	x -= y;
	if(x < 0) 
		x += MOD;
}

inline int getCounter(int l1, int c1, int l2, int c2) {
	l1 = max(l1, 1);
	c1 = max(c1, 1);
	l2 = min(l2, MAXC);
	c2 = min(c2, MAXC);

	if(l1 > l2|| c1 > c2) return 0;

	return counter[l2][c2] - counter[l1 - 1][c2] - counter[l2][c1 - 1] + counter[l1 - 1][c1 - 1];
}
 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, j, n, m, r;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> r;
    vector<int> x(n + 1), y(n + 1), b(n + 1);
    for(i = 1; i <= n; i++) {
    	cin >> x[i] >> y[i] >> b[i];
    	counter[x[i]][y[i]]++;
    }
    for(i = 1; i <= MAXC; i++) {
    	for(j = 1; j <= MAXC; j++) {
    		counter[i][j] += counter[i - 1][j] + counter[i][j - 1] - counter[i - 1][j - 1];
    	}
    }

    fact[0] = 1;
    for(i = 1; i <= MAXN; i++) {
    	fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    for(i = 0; i <= MAXN; i++) {
    	comb[i][0] = 1;
    	for(j = 1; j <= i; j++) {
    		add(comb[i][j], comb[i - 1][j - 1]);
    		add(comb[i][j], comb[i - 1][j]);
    		//aran[i][j] = (1LL * comb[i][j] * fact[j]) % MOD;
    	}
    }

    int ans = 0;
    for(i = 1; i <= n; i++) {
    	int cnt = getCounter(x[i] - r, y[i] - r, x[i] + r, y[i] + r);
    	int coef = (comb[n][m] - comb[n - cnt][m] + MOD) % MOD;
    	//cerr << coef << "\n";
    	ans = (ans + 1LL * coef * (1LL * b[i] * b[i] % MOD)) % MOD;
    }
    //cerr << ans << "\n";
    for(i = 1; i <= n; i++) {
    	int cnti = getCounter(x[i] - r, y[i] - r, x[i] + r, y[i] + r);
    	for(j = i + 1; j <= n; j++) {
    		int cntj = getCounter(x[j] - r, y[j] - r, x[j] + r, y[j] + r);
    		int cntij = getCounter(max(x[i] - r, x[j] - r), max(y[i] - r, y[j] - r),
    							   min(x[i] + r, x[j] + r), min(y[i] + r, y[j] + r));

    		int coefi = comb[n - cnti][m];
    		sub(coefi, comb[n - (cnti + cntj - cntij)][m]);
    		int coefj = comb[n - cntj][m];
    		sub(coefj, comb[n - (cnti + cntj - cntij)][m]);
    		int coefij = comb[n - (cnti + cntj - cntij)][m];

    		int coef = comb[n][m];
    		sub(coef, coefi);
    		sub(coef, coefj);
    		sub(coef, coefij);

    		ans = (ans + 2LL * coef * (1LL * b[i] * b[j] % MOD)) % MOD;
    	}
    }

    cout << ans;
 
    return 0;
}