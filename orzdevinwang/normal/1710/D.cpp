#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 2007;
int n, xn, dp[N][N];
char s[N][N];
struct node {
	int l, r;
} a[N];
vi e[N]; 
void lk(int u, int v) {	
	e[u].emplace_back(v);
	e[v].emplace_back(u);
}
int arr[N];
void getarr(int len) {
	if(len == 2) {
		arr[1] = 1, arr[2] = 2;
		return ;
	}
	if(len == 4) {
		arr[1] = 3, arr[2] = 1, arr[3] = 4, arr[4] = 2;
		return ;
	}
	getarr(len - 1), arr[len] = len, arr[len + 1] = 0;
	R(i, len, 1) 
		if(arr[i - 1] == len - 1 || arr[i + 1] == len - 1 || i == len) swap(arr[i], arr[i - 1]);
		else break;
} 
void build(int l, int r) {
	assert(r - l + 1 != 3);
	int posl = a[l].l, posr = a[r].r;
	L(i, a[l].l, a[l].r) if(s[i][a[r].r] == '1') posl = i;
	R(i, a[r].r, a[r].l) if(s[a[l].l][i] == '1') posr = i;
	assert(s[posl][posr] == '1');
	int len = r - l + 1;
	getarr(len);
	L(i, 1, len) {
		arr[i] += l - 1;
		if(arr[i] == l) arr[i] = posl;
		else if(arr[i] == r) arr[i] = posr;
		else arr[i] = a[arr[i]].l;
	}
	L(i, 1, len - 1) lk(arr[i], arr[i + 1]);
	a[l].r = a[r].r;
	L(i, l + 1, xn - (r - l)) a[i] = a[i + r - l];
	xn -= r - l; 
}
void Main() {
	cin >> n, xn = n;
	L(i, 1, n) cin >> (s[i] + i);
	L(i, 1, n) a[i].l = a[i].r = i, e[i].clear();
	for(int len = 2; len <= xn; len += 1) {
		L(l, 1, xn - len + 1) {
			int r = l + len - 1; 
			if(s[a[l].l][a[r].r] == '1') {
				build(l, r), len = 1;
				break ;
			}
		}
	}
	L(i, 1, n) for(const int &v : e[i]) if(v < i) cout << v << ' ' << i << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);  
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}