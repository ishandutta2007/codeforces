#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int LOG = 20;
int BLOCK;

int cnt[1 << LOG];
int pref[N];

struct Query{
	int left_bound;
	int right_bound;
	int index;
	bool operator< (Query &D){
		if(left_bound / BLOCK == D.left_bound / BLOCK)
			return right_bound < D.right_bound;
		return left_bound < D.left_bound;
	}
};

int main(){
	fastIO;
	BLOCK = 233;
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++ ){
		cin >> pref[i];
		pref[i] ^= pref[i - 1];
	}
	Query T[m];
	for(int x = 0;x < m ; x ++ ){
		cin >> T[x].left_bound >> T[x].right_bound;
		T[x].left_bound -- ;
		T[x].index = x;
	}
	ll ret[m];
	sort(T, T + m);
	int tl, tr;
	int cl = 0, cr = -1;
	ll ans = 0;
	for(int x = 0; x < m ; x ++ ){
		tl = T[x].left_bound;
		tr = T[x].right_bound;
		while(cr > tr){
			cnt[pref[cr]] -- ;
			ans -= cnt[pref[cr] ^ k];
			-- cr;
		}
		while(cr < tr){
			cr ++ ;
			ans += cnt[pref[cr] ^ k];
			cnt[pref[cr]] ++ ;
		}
		while(cl > tl){
			-- cl;
			ans += cnt[pref[cl] ^ k];
			cnt[pref[cl]] ++ ;
		}
		while(cl < tl){
			cnt[pref[cl]] -- ;
			ans -= cnt[pref[cl] ^ k];
			++ cl;
		}
		ret[T[x].index] = ans;
	}
	for(int d = 0; d < m ; d ++ ){
		cout << ret[d] << "\n";
	}
	return 0;
}