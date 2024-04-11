#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define sz(a) ((int) a.size())
#define vi vector<int>
#define ll long long
#define me(f, x) memset(f, x, sizeof(f))  
#define ull unsigned long long 
using namespace std;
const int N = 1e5 + 7;
int n, a, b, c, len[N], col[N], tp;
int lk, cur, xm[N];
char s[N];
ll ns;
void solve (int o) {
	ll sum = 0;
	int cnt[2] = {0, 0}, pt[2] = {0, 0};
	lk = 0;
	L(i, 1, tp) {
		cnt[col[i]] += len[i], pt[col[i]] += 1;
		if (!col[i] && i > 1 && i < tp) xm[++lk] = len[i];
	}
	sort(xm + 1, xm + lk + 1), reverse(xm + 1, xm + lk + 1);
	cur = lk;
	while (true) {
		o ^= 1;
		if (o) {
			if (pt[1] == cnt[1]) return ;
			cnt[1] -= 1;
			sum += b;
		} else {
			if (!cnt[0]) return ;
			while (cur > 0 && xm[cur] <= 1) -- cur; 
			if (pt[0] != cnt[0]) 
				ns = max(ns, sum + a);
			if (pt[1] == cnt[1]) {
				if (cur == lk) return ;
				sum -= c;
				pt[1] -= 1;
				pt[0] -= 1;
				xm[lk] = 0;
				lk -= 1;
			} else {
				if(cur) xm[cur] -= 1;
				else if(pt[0] == cnt[0]) {
					if (lk) xm[lk] = 0, lk -= 1, pt[1] -= 1;
					pt[0] -= 1;
					sum -= a + c;
				} 
				sum += a;
			}
			cnt[0] -= 1;
		}
		ns = max(ns, sum);
	}
}
void Main () {
	cin >> n >> a >> b >> c >> (s + 1), tp = 0; 
	L(i, 1, n) 
		if(!tp || s[i] - '0' != col[tp]) ++ tp, len[tp] = 1, col[tp] = s[i] - '0'; 
		else len[tp] += 1;
	ns = 0, solve (0), solve (1);
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio (false); cin.tie(0); 
	int t; 
	cin >> t; 
	while (t--) Main ();
	return 0;
}