#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1007;

#define i128 __int128 
inline i128 read() {
    char ch = getchar(); i128 r = 0, w = 1;
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) r = r * 10 + (ch - '0');
    return r * w;
}
inline void prt(i128 x) {
	if(x > 9) prt(x / 10);
	putchar(x % 10 + '0');
}

int n, m;
i128 a[N], b[N];

inline i128 Gcd(i128 a, i128 b) {
	if(!b) return a;
	while(b) 
		a %= b, swap(a, b); 
	return a;
}
struct dot {
	i128 stk[N], cur;
	int cnt[N], tp, sum;
	void init(i128 w) {
		me(cnt, 0);
		cur = w;
		tp = 1;
		stk[tp] = w;
	}
	void insert(i128 w) {
		L(i, 1, tp) {
			i128 g = Gcd(w, stk[i]);
			if(g != 1 && g != stk[i]) {
				R(j, tp, i) stk[j + 1] = stk[j];
				++ tp;
				stk[i + 1] = stk[i] / g;
				stk[i] = g;
			} 
			w /= g;
		}
		assert(w == 1);
	}
	void cover(i128 w, int op) {
		L(i, 1, tp) {
			if(w % stk[i] == 0) 
				sum -= cnt[i] == 0, cnt[i] += op, sum += cnt[i] == 0, w /= stk[i];
		}
	}
} A[N], B[N];


i128 gc[N][N];

bool visa[N], visb[N];
void Main () {
	n = read(), m = read();
	L(i, 1, n) a[i] = read(), A[i].init(a[i]);
	L(i, 1, m) b[i] = read(), B[i].init(b[i]);
	L(i, 1, n) 
		L(j, 1, m) 
			gc[i][j] = Gcd(a[i], b[j]), 
			A[i].insert(gc[i][j]), 
			B[j].insert(gc[i][j]);
	
	L(i, 1, n) visa[i] = true, A[i].sum = A[i].tp;
	L(i, 1, m) visb[i] = true, B[i].sum = B[i].tp;
	
	L(i, 1, n) 
		L(j, 1, m) 
			A[i].cover(gc[i][j], 1), 
			B[j].cover(gc[i][j], 1);
	
	int cnt = 0;
	while(true) {
		bool op = false;
		L(i, 1, n) if(!op && visa[i] && A[i].sum) {
			op = true, visa[i] = false;
			L(j, 1, m) 
				B[j].cover(gc[i][j], -1);
		}
		L(j, 1, m) if(!op && visb[j] && B[j].sum) {
			op = true, visb[j] = false;
			L(i, 1, n) 
				A[i].cover(gc[i][j], -1);
		}
		if(!op) break ;
		cnt += 1;
	}
	if(cnt == n + m) {
		cout << "NO\n";
	} else {
		vi sta, stb;
		L(i, 1, n) if(visa[i]) sta.emplace_back(i);
		L(i, 1, m) if(visb[i]) stb.emplace_back(i);
		cout << "YES\n";
		cout << sz(sta) << ' ' << sz(stb) << '\n';
		for(const int &u : sta) 
			prt(a[u]), cout << ' ';
		cout << '\n';
		for(const int &u : stb) 
			prt(b[u]), cout << ' ';
		cout << '\n';
	}
}

int main() {
	int t = read();
	while(t--) Main();
	return 0;
}