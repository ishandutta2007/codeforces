#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 20;
int n, pre[N];
char s[N];
int sl[N], sr[N];
int stk[N], tp;

int tag[N], mn[N];
void build(int x, int L, int R) {
	tag[x] = mn[x] = 0;
	if(L == R) return mn[x] = sl[L] ? 0 : 1e9, void ();
	int mid = (L + R) >> 1;
	build(x << 1, L, mid);
	build(x << 1 | 1, mid + 1, R);
	mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
}

void add(int x, int L, int R, int l, int r, int w) {
	if(l <= L && R <= r) 
		return tag[x] += w, mn[x] += w, void ();
	int mid = (L + R) >> 1;
	if(l <= mid) add(x << 1, L, mid, l, r, w);
	if(r > mid) add(x << 1 | 1, mid + 1, R, l, r, w);
	mn[x] = min(mn[x << 1], mn[x << 1 | 1]) + tag[x];
}

void Main () {
	cin >> n;
	cin >> (s + 1); 
	L(i, 1, n * 2) 
		pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
	bool ok = true;
	L(i, 1, n * 2) 
		if(pre[i] < 0) 
			 ok = false;
	if(ok) 
		return cout << "0\n", void ();
	sl[0] = sr[n * 2 + 1] = true;
	L(i, 1, n * 2) sl[i] = sl[i - 1] && (pre[i] >= 0);
	R(i, n * 2, 1) sr[i] = sr[i + 1] && (pre[i] >= 0);
	
	tp = 0, stk[0] = -1;
	
	build(1, 0, n * 2);
	L(i, 0, n * 2) {
		while(tp > 0 && pre[i] > pre[stk[tp]]) 
			add(1, 0, n * 2, stk[tp - 1] + 1, stk[tp], -pre[stk[tp]]), --tp;
		if(i) 
			add(1, 0, n * 2, stk[tp] + 1, i - 1, pre[i]);
		stk[++tp] = i; 
		if(sr[i]) {
			if(mn[1] <= pre[i]) {
				int mx = 0;
				R(l, i, 0) {
					mx = max(mx, pre[l]);
					if(sl[l] && mx <= pre[l] + pre[i]) {
//						cout << "PRE = " << mx << ' ' << pre[l] << "\n";
						cout << 1 << '\n';
						cout << l + 1 << ' ' << i << '\n';
//						reverse(s + l + 1, s + i + 1);
//						cout << (s + 1) << endl;
						return ;
					}
				}
				cout << endl;
				assert(false);
			}
		}
	}
	
//	L(l, 0, n * 2 - 1) {
//		L(r, l, n * 2) {
//			if(sl[l] && sr[r]) {
//				bool ok = true;
//				L(i, l + 1, r - 1) if(pre[i] - pre[l] > pre[r]) ok = false;
//				if(ok) {
//					cout << 1 << '\n';
//					cout << l + 1 << ' ' << r << endl;
//					return ;
//				}
//			} 
//		}
//	}
	
	int mx = 0;
	L(i, 1, n * 2) if(pre[mx] < pre[i]) mx = i;
	cout << 2 << '\n';
	cout << 1 << ' ' << mx << '\n';
	cout << mx + 1 << ' ' << n * 2 << '\n';
	reverse(s + 1, s + mx + 1);
	reverse(s + mx + 1, s + n * 2 + 1);
} 
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t ;
	cin >> t;
	while(t--) Main();
	return 0;
}