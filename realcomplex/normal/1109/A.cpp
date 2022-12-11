#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
int pref[N];

const int P = (1 << 20);
int cnt[2][P];

int main(){
	fastIO;
	int n;
	cin >> n;
	int x;
	ll answ = 0;
	cnt[0][0] ++ ;
	for(int i = 1; i <= n; i ++ ){
		cin >> x;
		pref[i] = pref[i - 1] ^ x;
		answ += cnt[i % 2][pref[i]];
		cnt[i % 2][pref[i]] ++ ;
	}
	cout << answ << "\n";
	return 0;
}