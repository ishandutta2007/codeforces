//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long int LL;
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

const int maxn = 1e5 + 10,
	  maxv = 300 * 1000;
pii seg[maxv * 4];
int laz[maxv * 4];
int ord[maxn],
	le[maxn],
	mi[maxn],
	ri[maxn],
	n, sz = 0;
vector<int> vec[maxv];

void build(int l = 0, int r = maxv, int id = 1){
	if(r - l == 1){
		seg[id] = MP(0, l);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id<<1|0);
	build(mid, r, id<<1|1);
	seg[id] = max(seg[id<<1|0], seg[id<<1|1]);
}

void add(int val, int st, int en, int l = 0, int r = maxv, int id = 1){
	if(st >= r or en <= l) return;
	if(st <= l and r <= en){
		seg[id].L += val;
		laz[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id<<1|0);
	add(val, st, en, mid, r, id<<1|1);
	seg[id] = max(seg[id<<1|0], seg[id<<1|1]);
	seg[id].L += laz[id];
}

bool cmp(int i, int j){
	return le[i] < le[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	build();
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> le[i] >> mi[i] >> ri[i], le[i]--, mi[i]--, ri[i]--, vec[mi[i]].PB(i);
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	int	ptr = 0,
		ans = 0,
		lans = -1,
		rans = -1;
	for(int lpos = 0; lpos < maxv; lpos++){
		while(ptr < n and le[ord[ptr]] <= lpos){
			add(+1, mi[ord[ptr]], ri[ord[ptr]] + 1);
			ptr++;
		}
		if(seg[1].L > ans){
			ans = seg[1].L;
			lans = lpos;
			rans = seg[1].R;
		}
		for(auto id : vec[lpos])
			add(-1, mi[id], ri[id] + 1);
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++)
		if(le[i] <= lans and ri[i] >= rans and mi[i] >= lans and mi[i] <= rans)
			cout << i + 1 << ' ';
	cout << '\n';
	return 0;
}