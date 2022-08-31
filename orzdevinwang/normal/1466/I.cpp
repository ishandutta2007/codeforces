#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, b, hb, stk[N], tp;
bool vis[N];
vi ns;
char s[N]; 
vi L[N], R[N], mx, cS;
int ck, usi;
void Print (int k, vi S) {
	ck = k, cS = S;
	if(k && R[k] <= mx) return usi = false, s[1] = 'n', void ();
	if(S >= R[k]) return usi = false, s[1] = 'n', void ();
	if(S <= L[k]) return usi = false, s[1] = 'y', void ();
	cout << k << ' ';
	for (const int &u : S) cout << u;
	cout << endl;
	usi = true;
}
bool Read () {
	if(usi) cin >> (s + 1);
	if(s[1] == 'y') return L[ck] = max(L[ck], cS), mx = max(mx, cS), true; // i > X
	return R[ck] = min(R[ck], cS), false; // i <= X
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> b, hb = b;
	L(i, 1, n) vis[i] = true;
	L(i, 0, n) 
		L[i].push_back(-114514), R[i].push_back(114514);
	L(i, 1, n) {
		R[i].clear ();
		L(j, 1, b) R[i].push_back(1);
	}
	while (b > 0) {
		tp = 0;
		L(i, 1, n) if(vis[i]) {
			while (true) {
				vi h = ns;
				while (sz(h) < hb) h.push_back(1);
				if(Print (i, h), Read ()) {
					if(!tp) assert (0);
					ns.pop_back(), vis[stk[tp]] = false, --tp;
					continue;
				}
				if(tp == b) break;
				h = ns, h.push_back(0);
				while (sz(h) < hb) h.push_back(1);
				if(Print (i, h), Read ()) ns.push_back(1);
				else ns.push_back(0);
				stk[++tp] = i;
				break; 
			}
		}
		int u = stk[tp] + 1;
		R(i, tp, 1) {
			vi h = ns;
			while (sz(h) < hb) h.push_back(1);
			if(Print (stk[i], h), Read ()) {
				while (tp > i) ns.pop_back(), vis[stk[tp]] = false, --tp;
			}
		}
		b -= tp;
	}
	Print (0, ns);
	return 0;
}