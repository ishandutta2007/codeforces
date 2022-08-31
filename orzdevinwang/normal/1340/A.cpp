#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, p[N], mp[N], cnt[N];
set < int > st;
multiset < int > mult;
void Main () {
	st.clear ();
	mult.clear ();
	cin >> n;
	L(i, 1, n + 1) st.insert (i), cnt[i] = 0;
	L(i, 1, n) mult.insert(0);
	L(i, 1, n) cin >> p[i], mp[p[i]] = i;
	L(i, 1, n) {
		int x = mp[i];
		if(cnt[x] != * mult.rbegin()) return cout << "No\n", void ();
		st.erase (x);
		int z = * st.lower_bound (x);
		mult.erase (mult.lower_bound (cnt[x]));
		if(z <= n) 
			mult.erase (mult.lower_bound(cnt[z])), cnt[z] += cnt[x] + 1, mult.insert (cnt[z]); 
	}
	cout << "Yes\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}