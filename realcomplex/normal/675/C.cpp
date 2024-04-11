#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<ll, int> cnt;

int main(){
	fastIO;
	int n;
	cin >> n;
	ll x;
	ll s = 0;
	int answ = n - 1;
	for(int i = 0 ; i < n; i ++ ){
		cin >> x;
		s += x;
		cnt[s] ++ ;
		answ = min(answ, n - cnt[s]);
	}
	cout << answ << "\n";
	return 0;
}