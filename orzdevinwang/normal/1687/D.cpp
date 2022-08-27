#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, V = 2e6 + 3;
int n, a[N], lst[V + 7], nxt[V + 7], S;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	S = a[1];
	R(i, n, 1) a[i] -= a[1];
	L(i, 1, n) nxt[a[i]] = a[i], lst[a[i]] = a[i];
	nxt[V + 1] = V + 1;
	R(i, V, 1) if(!nxt[i]) nxt[i] = nxt[i + 1];
	L(i, 1, V) if(!lst[i]) lst[i] = lst[i - 1];
	L(i, 0, V) {
		int l = -1e9, r = 1e9, ls = -1;
		L(ik, 0, V) {
			int Lv = ls + 1, Rv = ik * (ik + 1) + (2 * ik + 1) * i;
			if(lst[min(Rv, V)] >= Lv) {
				r = min(r, Rv - lst[min(Rv, V)]);
				l = max(l, ik * ik + (2 * ik) * i - nxt[Lv]);
			}
			if(Rv >= V) break ;
			ls = Rv;
		}
//		L(j, 1, n) {
//			int ik = 0; 
//			while(ik * (ik + 1) + (2 * ik + 1) * i < a[j]) ++ik; 
//			l = max(l, ik * ik + (2 * ik) * i - a[j]);  
//			r = min(r, ik * (ik + 1) + (2 * ik + 1) * i - a[j]); 
//		}
		if((ll) i * i + l <= S) l = max(l, (int) (S - (ll) i * i));
		if(l <= r) {
			cout << (ll) i * i + l - S << '\n';
			return 0;
		}
	}
	return 0;
}