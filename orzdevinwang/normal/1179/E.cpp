#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 12;
int n;
ll X, d, vl[N], vr[N];
int counting;
unordered_map < ll, ll > mp[N];
ll query (int x, ll p) {
	if(mp[x].count (p)) return mp[x][p];
//	if(p <= 5) return p;
//	else return 5;
	++counting;
	if(counting > 200000) exit (0);
	cout << "? " << x << ' ' << p << endl;
	ll r;
	cin >> r;
	return mp[x][p] = r;
}
mt19937_64 orz(time(0) ^ clock()); 
ll frm[N], To[N];

ll get (int z, ll l, ll r, ll gt) {
	ll ns = r;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if(query (z, mid) >= gt) ns = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ns;
}
void divide (vi S, ll L, ll R) {
	if(sz(S) == 1) 
		return vl[S[0]] = L, vr[S[0]] = R, void ();
	for (const int &z : S) frm[z] = query (z, L);
	int t = sz(S) / 2, all = sz(S);
	ll l = L, r = R, ns = -1;
	vi S1, S2;
	while (l <= r && sz(S) > 0) {
		shuffle (S.begin(), S.end(), orz);
		ll mid = (l + r) >> 1; 
		if (sz(S) > 5) 
			mid = get (S[0], l, r, frm[S[0]] + t * d);
		if(mid < l || mid > r) 
			assert (0);
		int cnt1 = sz(S2);
		vi Hs;
		for (const int &z : S) {
			To[z] = query (z, mid);
			if(To[z] < frm[z] + t * d) cnt1 += 1;
		} 
		if(cnt1 > all - t) {
			for (const int &z : S) {
				if(To[z] >= frm[z] + t * d) S1.push_back(z);
				else Hs.push_back(z);
			}
			S = Hs;
			l = mid + 1;
		}
		else {
			for (const int &z : S) {
				if(To[z] < frm[z] + t * d) S2.push_back(z);
				else Hs.push_back(z);
			}
			S = Hs;
			ns = mid, r = mid - 1;	
		}
	}
	if(ns == -1) 
		assert (0);
	
	for (const int &z : S) To[z] = query (z, ns);
	for (const int &z : S) {
		if(To[z] > frm[z] + t * d) S1.push_back(z); 
		if(To[z] < frm[z] + t * d) S2.push_back(z);
	}
	for (const int &z : S) if(To[z] == frm[z] + t * d) {
		if(sz(S1) < t) S1.push_back(z); 
		else S2.push_back(z);
	}
	divide (S1, L, ns);
	divide (S2, ns, R);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> X;
	d = X / n;
	vi S;
	L(i, 1, n) S.push_back(i);
	divide (S, 0, 1e18);
	cout << "!\n";
	L(i, 1, n) cout << vl[i] << ' ' << vr[i] << '\n';
	return 0;
}