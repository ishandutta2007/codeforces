#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = (1 << 22) + 1;
int n, p[N];
mt19937_64 orz(time(0) ^ clock());
int a[N];
int cyc;
bool vis[N];
int calc(int *p) {
	int cnt = 0;
	L(i, 1, n) cnt += p[i] == i;
//	L(i, 1, n) vis[i] = false;
//	L(i, 1, n) if(!vis[i]) {
//		int u = i;
//		while(!vis[u]) vis[u] = true, u = p[u];
//		cnt += 1;
//	}
	return cnt;
}
int get(int xn) {
	L(i, 1, n) a[i] = i;
	L(i, 1, xn) {
		int u = orz() % n + 1;
		int v = orz() % n + 1;
		while(u == v) u = orz() % n + 1, v = orz() % n + 1;
		swap(a[u], a[v]);
	}
	return calc(a);
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	n = 1000;
	cin >> n;
	if(n == 5) return cout << "Petr\n", 0;
	double sum1 = 0, sum2 = 0;
	L(o, 1, 5) {
		sum1 += get(3 * n);
	}
	sum1 /= 5;
	L(o, 1, 5) {
		sum2 += get(7 * n + 1);
	} 
	sum2 /= 5;
	L(i, 1, n) cin >> p[i];
	int gt = calc(p);
//	cout << sum1 << ' ' << sum2 << ' ' << gt << endl;
	if(fabs(gt - sum1) < fabs(gt - sum2)) {
		cout << "Petr\n";
	} else {
		cout << "Um_nik\n";
	}
	return 0;
}