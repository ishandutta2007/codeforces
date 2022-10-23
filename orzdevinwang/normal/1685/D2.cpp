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
const int N = 407;
int n, a[N], q[N], f[N], qf[N], to[N];  
bool vis[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int s[N];
bool vl[N], vr[N], bq[N];
void mg(int u, int v) { f[find(u)] = find(v); }

bool check() { 
	me(vl, 0), me(vr, 0), me(bq, 0);
	L(i, 1, n) f[i] = qf[i];
	L(i, 1, n) s[i] = 0; 
	L(i, 1, n) if(q[i]) {
		s[i] = -1, bq[a[q[i]]] = true;
		if(q[i] != to[i]) {
			s[i] = a[q[i]];
			if(qf[s[i]] == qf[i]) return false;
			mg(i, s[i]);
			if(i < s[i]) {
				L(j, i, s[i] - 1) {
//					cout << "VL " << j << endl;
					if(vl[j]) return false; 
					vl[j] = true;
				}
			} else {
				L(j, s[i], i - 1) {
//					cout << "VR " << j << endl;
					if(vr[j]) return false; 
					vr[j] = true;
				}
			}
		}
	}
//	cout << "qwq" << endl;
	L(i, 1, n) f[i] = qf[i];
	L(i, 1, n - 1) if(vl[i] || vr[i]) {
		if(find(i) == find(i + 1)) return false;
		mg(i, i + 1);
	} 
	L(i, 1, n) bq[i] &= (q[i] != 0);
//	L(i, 1, n) cout << bq[i];
//	cout << endl;
	L(i, 2, n - 1) if(vl[i - 1] && vr[i - 1] && vl[i] && vr[i] && !bq[i]) return false;
	L(i, 1, n - 1) if(!bq[i] && !bq[i + 1]) mg(i, i + 1);
	L(i, 1, n) if(find(i) != find(1)) return false;
	return true;
}
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i], to[a[i]] = i; 
//	L(i, 1, n) cout << to[i] << ' ';
//	cout << endl;
	L(i, 1, n) f[i] = i;
	L(i, 1, n) f[find(to[i])] = find(i);
	L(i, 1, n) qf[i] = find(i);
	me(vis, 0), me(q, 0);
	int u = 1;
	vis[u] = true;
	cout << 1 << ' ';
	L(rt, 1, n - 1) {
		L(z, 1, n + 1) if(!vis[z]) {
//			cout << "z = " << z << endl;
			assert(z <= n);
			vis[z] = true, q[u] = z;
			if(check()) {
				u = z;
				break ;
			}
			vis[z] = false;
		}
		cout << u << ' ';
	}
	cout << '\n';
}
int main() { 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}
/*
1
5
4 5 3 1 2
*/