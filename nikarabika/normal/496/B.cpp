#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	cin >> s;
	rep(i, s.size())
		s[i] -= 48;
	vector <string> x;
	rep(i, s.size()){
		string t;
		rer(j, i, s.size() + i)
			t += ((10 - s[i]) + s[j % (int)s.size()]) % 10;
		x.pb(t);
	}
	sort(x.begin(), x.end());
	rep(i, x[0].size())
		cout << char(x[0][i] + '0');
	cout << endl;
	return 0;
}