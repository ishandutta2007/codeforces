//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 * 1000 + 85 - 69;
LL fen[maxn],
   a[maxn],
   n, k;
vector<LL> all;

void inc(int idx){
	idx++;
	while(idx < maxn){
		fen[idx]++;
		idx += idx & -idx;
	}
	return;
}

LL get(int idx){
	LL ret = 0;
	while(idx > 0){
		ret += fen[idx];
		idx -= idx & -idx;
	}
	return ret;
}

LL get_ans(LL minsum){
	memset(fen, 0, sizeof fen);
	LL ret = 0;
	for(int i = 0; i <= n; i++){
		int id1 = lower_bound(all(all), a[i]) - all.begin(),
			id2 = upper_bound(all(all), a[i] - minsum) - all.begin();
		ret += get(id2);
		inc(id1);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	all.PB(0);
	for(int i = 0; i < n; i++){
		LL x;
		cin >> x;
		a[i + 1] = a[i] + x;
		all.PB(a[i + 1]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	LL hi = 100000LL * 1000 * 1000 * 1000 + 1;
	LL lo = -hi;
	while(hi - lo > 1){
		LL mid = (lo+hi)>>1;
		if(get_ans(mid) < k)
			hi = mid;
		else
			lo = mid;
	}
	cout << lo << endl;
	return 0;
}