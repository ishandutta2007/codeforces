#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> pos;

int calc(int l, int r){
	int fr = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
	int sr = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
	return sr - fr;
}

ll a, b;

ll answer(int l, int r){
	if(calc(l, r) == 0)
		return a;
	int mid = (l + r) / 2;
	ll answ = (ll)1e15;
	if(l != r)
		answ = answer(l, mid) + answer(mid + 1, r);
	answ = min(answ, (r - l + 1) * 1ll * calc(l, r) * b);
	return answ;
}

int main(){
	fastIO;
	int n, k;
	cin >> n >> k >> a >> b;
	int sz = (1 << n);
	int q;
	for(int i = 0 ; i < k ; i ++ ){
		cin >> q;
		-- q;
		pos.push_back(q);
	}
	sort(pos.begin(), pos.end());
	cout << answer(0, sz - 1);
	return 0;
}