#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int P[4];
int n, x[N], y[N], c[N], arr[N], tot, ns;
vi sx[N][4], sy[N][4];
bool vis[N], usi[N];
bool check1 (int mi) {
	L(i, 1, n) usi[i] = false;
	int p = 0, cnt = 0, ok = 0;
	L(i, 1, n) {
		for (const int &t : sx[i][P[1]]) cnt += 1, usi[t] = true;
		if(cnt >= mi) {
			p = i;
			break ;	
		}
	}
	p += 1, cnt = 0;
	L(i, p, n) {
		for (const int &t : sx[i][P[2]]) cnt += 1, usi[t] = true;
		if(cnt >= mi) {
			p = i, ok = 1;
			break ;	
		}
	}
	if(!ok) return false;
	cnt = 0;
	L(i, p + 1, n) for (const int &t : sx[i][P[3]]) cnt += 1, usi[t] = true;
	return cnt >= mi;
}
bool check2 (int mi) {
	L(i, 1, n) usi[i] = false;
	int p = 0, cp = 0, cnt = 0, ok = 0;
	L(i, 1, n) {
		for (const int &t : sx[i][P[1]]) cnt += 1, usi[t] = true;
		if(cnt >= mi) {
			p = i;
			break ;	
		}
	}
	p += 1, cnt = 0;
	L(i, 1, n) {
		for (const int &t : sy[i][P[2]]) if(x[t] >= p) cnt += 1, usi[t] = true;
		if(cnt >= mi) {
			cp = i, ok = 1;
			break ;	
		}
	}
	if(!ok) return false;
	cnt = 0;
	L(i, cp + 1, n) for (const int &t : sy[i][P[3]]) if(x[t] >= p) cnt += 1, usi[t] = true;
	return cnt >= mi;
}
void solve () {
	L(i, 1, 3) P[i] = i;
	L(i, 1, n) L(j, 1, 3) sx[i][j].clear (), sy[i][j].clear ();
	L(i, 1, n) sx[x[i]][c[i]].push_back(i), sy[y[i]][c[i]].push_back(i);
	do {
		int l = ns + 1, r = n / 3;
		while (l <= r) {
			int mid = (l + r) >> 1, ok = check1(mid);
			if(!ok) ok = check2(mid);
			if(ok) {
				ns = mid;
				L(j, 1, n) vis[j] = usi[j];
				l = mid + 1;
			} 
			else r = mid - 1;
		}
	} while (next_permutation(P + 1, P + 4));
} 
int mt[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0); 
	cin >> n;
	L(i, 1, n) cin >> x[i] >> y[i] >> c[i];
	tot = 0;
	L(i, 1, n) arr[++tot] = x[i];
	sort(arr + 1, arr + tot + 1);
	tot = unique(arr + 1, arr + tot + 1) - arr - 1;
	L(i, 1, n) x[i] = lower_bound (arr + 1, arr + tot + 1, x[i]) - arr;
	tot = 0;
	L(i, 1, n) arr[++tot] = y[i];
	sort(arr + 1, arr + tot + 1);
	tot = unique(arr + 1, arr + tot + 1) - arr - 1;
	L(i, 1, n) y[i] = lower_bound (arr + 1, arr + tot + 1, y[i]) - arr;
	solve ();
	L(i, 1, n) x[i] = n - x[i] + 1;
	solve ();
	L(i, 1, n) swap(x[i], y[i]);
	solve ();
	L(i, 1, n) x[i] = n - x[i] + 1;
	solve ();
	cout << ns * 3 << '\n';
	return 0;
}