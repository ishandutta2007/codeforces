#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
 
#define FNAME ""
 
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
       
	int n, k;
	cin >> n;
	int flag = 0;
	forn (i, n) {
		cin >> k;
		if (k % 2 == 0)
			cout << k / 2 << "\n";
		else {
			int l = k / 2;
			if (flag == 0) {
				if (k < 0)
					l--;
			} else if (k > 0)
				l++;
			cout << l << "\n";
			flag ^= 1;
		}
	}
 
    return 0;
}