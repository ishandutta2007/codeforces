//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB emplace_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2e5 + 85;
const LL Inf = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000 * 8;
vector<int> tmp[maxn * 4],
	vec[maxn * 4];
vector<LD> its[maxn * 4];
LL arr[maxn],
   s[maxn],
   ss[maxn],
   a[maxn],
   b[maxn];
int n;

bool cmp(int i, int j){
	return a[i] != a[j] ? a[i] > a[j] : b[i] > b[j];
}

LD Intersect(int i, int j){
	return LD(b[i] - b[j]) / LD(a[j] - a[i]);
}

void build(int l = 0, int r = n, int id = 1){
	vec[id].reserve(r - l);
	tmp[id].reserve(r - l);
	if(r - l == 1){
		vec[id].PB(l);
		tmp[id].PB(l);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	merge(all(vec[id * 2 + 0]),
			all(vec[id * 2 + 1]),
			back_inserter(tmp[id]), cmp);
	for(auto idx : tmp[id]){
		while(sz(vec[id]) and a[vec[id].back()] == a[idx])
			vec[id].pop_back();
		while(sz(vec[id]) >= 2 and Intersect(vec[id][sz(vec[id]) - 1], idx) < Intersect(vec[id][sz(vec[id]) - 2], vec[id][sz(vec[id]) - 1]))
			vec[id].pop_back();
		vec[id].PB(idx);
	}
	for(int i = 0; i + 1 < sz(vec[id]); i++)
		its[id].PB(Intersect(vec[id][i], vec[id][i + 1]));
	return;
}

LL get(LL xx, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return Inf;
	if(st <= l and r <= en){
		int idx = *(lower_bound(all(its[id]), LD(xx)) - its[id].begin() + vec[id].begin());
		return a[idx] * xx + b[idx];
	}
	int mid = (l + r) >> 1;
	return min(get(xx, st, en, l, mid, id * 2 + 0),
			get(xx, st, en, mid, r, id * 2 + 1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	n++;
	LL ans = 0;
	for(int i = 1; i < n; i++)
		cin >> arr[i];
	reverse(arr + 1, arr + n);
	for(LL i = 1; i < n; i++){
		s[i] = s[i - 1] + arr[i];
		ss[i] = ss[i - 1] + s[i];
		a[i] = s[i];
		b[i] = ss[i] - i * s[i];
	}
	build();
	for(LL i = 1; i < n; i++)
		smax(ans, ss[i] - get(i, 0, i));
	cout << ans << endl;
	return 0;
}