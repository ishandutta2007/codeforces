#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define ull unsigned long long 
#define sz(a) ((int) a.size())
#define vi vector<int>
#define me(a, x) memset(a, x, sizeof(a))
using namespace std;
const int N = 1e5 + 7;
int n, L[N], R[N], Lst[N];
char s[N]; 
ll ns;

int lg[N];
struct RMQ {
	int a[N], mx[20][N];
	void init (int n) {
		L(i, 1, n) mx[0][i] = i;
		L(i, 1, 19)
			L(j, 1, n - (1 << i) + 1) 
				mx[i][j] = a[mx[i - 1][j]] > a[mx[i - 1][j + (1 << (i - 1))]] ? 
					mx[i - 1][j] : mx[i - 1][j + (1 << (i - 1))];
	}
	int queryp (int l, int r) {
		int p = lg[r - l + 1];
		return a[mx[p][l]] < a[mx[p][r - (1 << p) + 1]] ? mx[p][r - (1 << p) + 1] : mx[p][l];
	}
} ;

struct inter {
	int l, r;
	inter (int L = 0, int R = 0) {
		l = L, r = R;
	}
};
inline inter operator + (inter a, inter b) {
	return inter(min(a.l, b.l), max(a.r, b.r));
}

int mas[20][N];
int slv(int l, int r) {
	int p = lg[r - l + 1];
	return mas[p][l] | mas[p][r - (1 << p) + 1];
}

inter a[N];

RMQ mnl, mxr;
inter f[20][N];
ll sl[20][N], sr[20][N];

inter mvk(inter x, int k) {
	int a = mnl.queryp(x.l, x.r);
	int b = mxr.queryp(x.l, x.r);
	return f[k][a] + f[k][b];
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> (s + 1), n = strlen(s + 1);
	L(i, 1, n) L[i] = 1, R[i] = n;
	L(i, 2, n) lg[i] = lg[i >> 1] + 1;
	L(i, 1, n) {
		int ls = Lst[s[i] - 'a'];
		if(ls) L[i] = ls, R[ls] = i;
		Lst[s[i] - 'a'] = i;
	} 
	L(i, 1, n) mnl.a[i] = -L[i], mxr.a[i] = R[i], a[i] = inter(L[i], R[i]);
	mnl.init(n), mxr.init(n);
	L(i, 1, n) f[0][i] = a[i], sl[0][i] = i - 1, sr[0][i] = n - i;
	L(i, 1, n) mas[0][i] = 1 << (s[i] - 'a');
	L(o, 1, 17) L(i, 1, n - (1 << o) - 1) mas[o][i] = mas[o - 1][i] | mas[o - 1][i + (1 << (o - 1))]; 
	L(o, 1, 17) { 
		L(i, 1, n) {
			sl[o][i] = sl[o - 1][i], sr[o][i] = sr[o - 1][i], f[o][i] = mvk(f[o - 1][i], o - 1);
			inter x = f[o - 1][i];
			int cur = 1 << (o - 1); 
			while(cur) {
				R(j, 17, 0) if(cur >= (1 << j)) {
					int a = mnl.queryp(x.l, x.r), b = mxr.queryp(x.l, x.r);
					auto u = f[j][a] + f[j][b];
					if(slv(u.l, u.r) == slv(x.l, x.r)) {
						sl[o][i] += sl[j][a] - a + x.l;
						sr[o][i] += sr[j][b] - x.r + b;
						cur -= 1 << j;
						x = u;
					}
				}
				if(cur) sl[o][i] += x.l - 1, sr[o][i] += n - x.r, x = mvk(x, 0), --cur;
			} 
		}
	}
	L(x, 1, n) ns += sl[17][x], ns += sr[17][x];
	cout << ns << '\n'; 
	return 0;
}