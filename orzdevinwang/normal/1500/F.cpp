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

namespace abab {
	ll a[N], F[N], lst[N], lstv[N];
	int n;
	bool ok[N], abl[N];
	bool work() {
		L(i, 0, n + 1) F[i] = abl[i] = ok[i] = false;
		
		ll l = 0, r = a[1], lk = 1;
		
		ok[1] = abl[1] = true;
		
		set < pair < ll, int > > S; 
		ll AD = 0;
		
		// For i % 2 = 1 : the set is AD + x
		// else : the set is AD - x
		
		L(i, 1, n) { 
			if(i > 1) {
				swap(l, r), l = a[i - 1] - l, r = a[i - 1] - r;
				r = min(r, a[i]);
				l = max(l, 0ll);

				if(l <= r) abl[i] = true, lst[i] = lk, lstv[i] = l;
				if(l <= a[i] && a[i] <= r && i < n) 
					ok[i] = true, lst[i] = lk, lstv[i] = a[i];
				
				AD = a[i - 1] - AD;
				
				auto GV = [&] (ll x) {
					return (i & 1) ? (AD + x) : (AD - x);
				} ; 
				
				auto chk = [&] (pair < ll, int > x) {
					ll w = GV(x.first);
					if(i < n && w == a[i]) 
						ok[i] = true, lst[i] = x.second, lstv[i] = w;
					return (0 <= w && (i == n || w <= a[i]));
				} ;
				
				while(sz(S) && !chk(*S.begin())) S.erase(S.begin());
				while(sz(S) && !chk(*--S.end())) S.erase(--S.end());
				
				if(!ok[i] && sz(S)) lst[i] = (*S.begin()).second, 
						lstv[i] = GV((*S.begin()).first), abl[i] = true;
			}
			
			if(ok[i]) {
				l = 0, r = a[i], lk = i, S.clear();
			} else {
				if(!abl[i]) return false;	
				if(a[i - 1] <= a[i]) {
					if(i & 1) S.insert(make_pair(a[i - 1] - AD, i)); 
					else S.insert(make_pair(AD - a[i - 1], i)); 
				}
			} 
		}
		int p = n;
		F[n] = a[n - 1];
		while (p > 1) {
			if(ok[lst[p]]) {
				ll w = a[p - 1] - lstv[p];
				R(i, p - 1, lst[p] + 1) F[i] = w, w = a[i - 1] - w;
				F[lst[p]] = a[lst[p]];
			} else {
				ll w = a[p - 1] - lstv[p];
				R(i, p - 1, lst[p]) F[i] = w, w = a[i - 1] - w;
			}
			p = lst[p];
		}
//		L(i, 1, n) cout << F[i] << ' ';
//		cout << endl; 
		L(i, 1, n) assert(F[i] >= 0);
		L(i, 1, n - 1) assert((max(F[i], F[i + 1]) == a[i]) || (F[i] + F[i + 1] == a[i]));
		
		L(i, 0, n + 1) a[i] = lst[i] = lstv[i] = 0;
		return true;
	}
} ;

int n;
ll C, a[N], F[N], h[N];
bool vis[N];
 
int main() {
//	freopen("data.txt", "r", stdin);
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n >> C;
	
	n -= 1;
	
	L(i, 1, n - 1) cin >> a[i];
	
	L(i, 1, n - 2) 
		if(a[i] == a[i + 1]) 
			vis[i] = true;
	vis[0] = true, vis[n - 1] = true;
	L(i, 1, n - 1) {
		if(vis[i - 1]) {
			abab :: n = 1;
			L(j, i, n - 1) {
				abab :: a[abab :: n] = a[j];
				abab :: n += 1;
				if(vis[j]) break ;
			}
			if(!abab :: work ()) return cout << "NO\n", 0;
			L(j, 1, abab :: n) 
				F[j + i - 1] = abab :: F[j];
		}
	}
	
	L(i, 1, n - 2) if(a[i] == a[i + 1]) F[i + 1] = a[i];
	
	cout << "YES\n";
	
	h[1] = F[1];
	L(i, 2, n) {
		if(max(F[i - 1], F[i]) == a[i - 1]) {
			h[i] = (h[i - 1] < 0 ? F[i] : -F[i]);
		} else h[i] = (h[i - 1] > 0 ? F[i] : -F[i]);
	}
	L(i, 1, n) 
		h[i] += h[i - 1];
	ll mn = 0;
	L(i, 1, n) 
		mn = min(mn, h[i]);
	L(i, 0, n) 
		h[i] -= mn;
	L(i, 0, n) 
		cout << h[i] << ' ';
	cout << '\n';
	return 0;
}