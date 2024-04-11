#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;

const int N = (int)1e5 + 9;


int pw[N];
int p0[N];
int p1[N];

int main(){
	int n, q;
	cin >> n >> q;
	char s;
	for(int i = 1; i <= n; i ++ ){
		cin >> s;
		if(s == '0')
			p0[i] = 1;
		else
			p1[i] = 1;
		p0[i] += p0[i - 1];
		p1[i] += p1[i - 1];
	}
	pw[0] = 1ll;
	for(int i = 1; i <= n; i ++ ){
		pw[i] = pw[i - 1];
		pw[i] *= 2ll;
		pw[i] %= MOD;
	}
	int lf, rf;
	int zero, one;
	int ans;
	for(int i = 0 ;i < q; i ++ ){
		cin >> lf >> rf;
		zero = p0[rf] - p0[lf - 1];
		one = p1[rf] - p1[lf - 1];
		ans = (pw[one] - 1 + MOD) % MOD;
		if(zero != 0){
			ans = (1ll * ans * ((pw[zero]) % MOD)) % MOD;
		}
		cout << ans << "\n";
	}
}