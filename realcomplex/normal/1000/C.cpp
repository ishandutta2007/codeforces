#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const int N = (int)4e5 + 9;
ll cnt[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	ll l, r;
	vector<pii> p;
	for(int i = 0 ; i < n;i ++ ){
		cin >> l >> r;
		p.push_back(mp(l, 1));
		p.push_back(mp(r + 1, -1));
	}
	sort(p.begin(), p.end());
	ll las = 0;
	bool ok;
	int i = 0;
	int c = 0;
	while(i < p.size()){
		cnt[c] += p[i].fi - las;
		c += p[i].se;
		las = p[i].fi;
		i ++ ;
	}
	for(int i = 1; i <= n; i ++ )
		cout << cnt[i] << " ";
	return 0;
}