#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	pie a[n];
	vector<int> ans;
	rep(i, n){
		cin >> a[i].p1;
		a[i].p2 = i + 1;
	}
	sort(a, a + n);
	int p = 0;
	while(k >= 0 and p < n){
		k -= a[p].p1;
		if(k >= 0)
			ans.PB(a[p].p2);
		p++;
	}
	cout << ans.size() << endl;
	rep(i, ans.size())
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}