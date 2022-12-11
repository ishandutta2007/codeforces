#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

int ans[N];

int main(){
	fastIO;
	set<int> smal;
	int n;
	cin >> n;
	vector<pii> id;
	int a;
	for(int i = 1; i <= n; i ++ ){
		cin >> a;
		id.push_back(mp(a, i));
	}
	sort(id.begin(), id.end());
	
	int low = id[0].fi;
	
	smal.insert(0);
	smal.insert(n + 1);
	
	int ix;
	int dis;
	int L, R;
	for(int i = 1; i <= n; i ++ ){
		a = id[i - 1].fi;
		ix = id[i - 1].se;
		dis = 0;
		auto it = smal.lower_bound(ix);
		R = *it;
		-- it;
		L = *it;
		R -- ;
		L ++ ;
		smal.insert(ix);
		ans[R - L + 1] = max(ans[dis], a);
	}
	for(int i = n; i >= 1; i -- ){
		if(ans[i] == 0 && ans[i + 1] == 0){
			ans[i] = low;
		}
		else{
			ans[i] = max(ans[i], ans[i + 1]);
		}
	}
	for(int i = 1; i <= n; i ++ ){
		cout << ans[i] << " ";
	}
	return 0;
}