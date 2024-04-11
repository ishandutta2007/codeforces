#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 2e6 + 7;
int n, l;
ll t[N], w1[N], w2[N];
ll ns1[N], ns2[N];
ll ti[N], wi[N]; // l * t_i + pre_i = w_i 
bool solve (ll *f, ll *ns) { 
	ll L = 0, R = l;
	L(i, 1, n) {
		f[i] += t[i];
		if(f[i] < 0 || f[i] % 2 == 1) return false;	
		f[i] /= 2;
	}
//	L(i, 0, l) cout << t[i] << " : " << f[i] << "\n"; 
	L(i, 0, l) wi[i] = ti[i] = -1;
	ti[0] = wi[0] = 0;
	ti[l] = -1, wi[l] = 0;
	L(i, 1, n) {
		ll p = t[i] % l, k = t[i] / l;
		if(wi[p] != -1) {
//			cout << k - ti[p] << endl;
			if((f[i] - wi[p]) % (k - ti[p])) return false;
			ll c = (f[i] - wi[p]) / (k - ti[p]);
			L = max(L, c), R = min(R, c);
		}
		else ti[p] = k, wi[p] = f[i];
	}
	int lst = 0;
	L(i, 1, l) if(wi[i] != -1) {
		ll buf = ti[lst] - ti[i], rl = wi[lst] - wi[i], rr = wi[lst] - wi[i] + i - lst;
		if (buf < 0) swap (rl, rr), rl = -rl, rr = -rr, buf = -buf;
		if (buf > 0) {
			L = max(L, (rl + buf - 1) / buf);
			R = min(R, rr / buf);
		}
		else if(rl > 0 || rr < 0) return  false; 
		// rl <= Sk <= rr 
		lst = i;
	}
	if(L > R) return false;
//	cout << L << ' ' << R << '\n';
	lst = 0;
	L(i, 1, l) if(wi[i] != -1) {
		ll x = wi[i] - wi[lst] - (ll) L * (ti[i] - ti[lst]);
//		cout << "x = " << x << '\n';
		L(j, lst + 1, i) {
			if(x > 0) ns[j] = 1, x -= 1;
			else ns[j] = 0;
		}
		lst = i;
//		cout << "x = " << x << '\n';
	}
//	L(i, 1, l) cout << ns[i] << ' ';
//	cout << '\n';
	return true;
}
int main () {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n >> l;
	L(i, 1, n) {
		ll x, y;
		cin >> t[i] >> x >> y;
		w1[i] = x + y;
		w2[i] = x - y;
	}
	if(!solve (w1, ns1)) return cout << "NO\n", 0;
	if(!solve (w2, ns2)) return cout << "NO\n", 0;	
	L(i, 1, l) {
		if(ns1[i] == 1 && ns2[i] == 1) cout << "R";
		if(ns1[i] == 1 && ns2[i] != 1) cout << "U";
		if(ns1[i] != 1 && ns2[i] != 1) cout << "L";
		if(ns1[i] != 1 && ns2[i] == 1) cout << "D";
	}
	return 0;
}
/*
1 2000000
17615333550771 3003414295 731036098
*/