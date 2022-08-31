#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7;
int n, k, a[N], cnt[N];

map < int, int > mp;
int lim;

int Z[N], r[N], T;
int check(int mid) {
	T = 0;
	for(auto u : mp) 
		if(u.first >= mid) 
			Z[++T] = u.second;
	sort(Z + 1, Z + T + 1);
	int ret = 0, S = k;
	L(i, 1, T) 
		if(S >= Z[i]) 
			S -= Z[i], ret += 1;
	return r[mid] > k ? -1 : T - ret;
} 

void Main() {
	cin >> n >> k;
	L(i, 1, n) cin >> a[i];
	mp.clear();
	
	L(i, 0, n) cnt[i] = 0; 
	L(i, 1, n) {
		if(a[i] <= n) cnt[a[i]] += 1;
		mp[a[i]] += 1;
	}
	
	lim = 0;
	L(i, 1, n) r[i] = r[i - 1] + (cnt[i - 1] == 0);
	
	int L = 0, R = n, ns = 1e9;
	while(L <= R) {
		int mid = (L + R) >> 1;
		int qwq = check(mid);
		if(qwq != -1) ns = min(ns, max(qwq, (int) !mid)), L = mid + 1;
		else R = mid - 1;
	} 
	cout << ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}