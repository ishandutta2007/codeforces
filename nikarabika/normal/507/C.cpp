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

ll ans = 0;
ull P[55];

void F(int h, ll n, char dir){
	if(h == 0)
		return;
	ans ++;
	if(dir == 'L'){
		if(n > P[h - 1]){
			F(h - 1, n - P[h - 1], 'R');
			return;
		}
		else{
			ans += P[h];
			ans --;
			F(h - 1, n, 'L');
			return;
		}
	}
	else{
		if(n <= P[h - 1]){
			F(h - 1, n, 'L');
			return;
		}
		else{
			ans += P[h];
			ans --;
			F(h - 1, n - P[h - 1], 'R');
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	ll h, n;
	cin >> h >> n;
	P[0] = 1;
	reu(i, 1, 50)
		P[i] = P[i - 1] * 2;
	F(h, n, 'R');
	cout << ans << endl;
	return 0;
}