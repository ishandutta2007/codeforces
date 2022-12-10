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

const int maxn = 1e5;
int d[maxn], s[maxn];
vector<pie> ans;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	set<pie> S;
	rep(i, n){
		int fi, se;
		cin >> fi >> se;
		d[i] = fi;
		s[i] = se;
		S.insert(mp(d[i], i));
	}
	while(S.size()){
		int x = S.begin()->p2;
		int par = s[x];
		S.erase(S.begin());
		if(d[x] != 1)
			continue;
		if(S.find(mp(d[par], par)) == S.end())
			continue;
		ans.pb(mp(x, par));
		s[par] ^= x;
		S.erase(mp(d[par], par));
		d[par]--;
		S.insert(mp(d[par], par));
	}
	cout << ans.size() << endl;
	rep(i, ans.size())
		cout << ans[i].p1 << ' ' << ans[i].p2 << endl;
	
	return 0;
}