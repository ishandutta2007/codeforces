#include <bits/stdc++.h>
#define IOS cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
using namespace std;

typedef long long ll;

const int N = 1e5 + 13;
int a[N];

class segment_tree{
	typedef struct {
		int64_t max;
		int maxc;
		int64_t min;
		int64_t lazy_update;
		int64_t sum;
	} value_type;
	
	int n;
	std::vector<value_type> a;

public:
	segment_tree() = default;
	segment_tree(int _n){
		n = 1; while(n < _n) n *= 2;
		a.resize(2 * n - 1); 
		tag<UPDATE>(0, 0);
	}
	template <class InputIterator>
	segment_tree(InputIterator first, InputIterator last) {
		int _n = std::distance(first, last);
		n = 1; while(n < _n) n *= 2;
		a.resize(2 * n - 1);
		for(int i = 0; i < _n; i++) {
			tag<UPDATE>(n - 1 + i, *(first + i));
		}
		for(int i = _n; i < n; i++) {
			tag<UPDATE>(n - 1 + i, 0);
		}
		for(int i = n - 2; i >= 0; i--){
			update(i);
		}
	}
	
	void range_chmod(int l, int r, int64_t value) {
		assert(0 <= l && l <= r && r <= n);
		range_apply<CHMOD>(0, 0, n, l, r, value);
	}
	void point_update(int x, int64_t value) {
		assert(0 <= x && x <= n);
		range_apply<UPDATE>(0, 0, n, x, x + 1, value);
	}
	
	int64_t range_sum(int l, int r) {
		assert(0 <= l && l <= r && r <= n);
		return range_get<SUM>(0, 0, n, l, r);
	}

	void crawl(int i, int l, int r){
		cout << i << " [" << l << "," << r << ") -> " << "mx: " << a[i].max << ", mxc: " << a[i].maxc << ", mn: " << a[i].min << ", sum: " << a[i].sum << ", lz_upd: " << (a[i].lazy_update == INT64_MAX ? "+oo" : to_string(a[i].lazy_update)) << endl;
		if(l + 1 != r){
			crawl(i * 2 + 1, l, (l + r) / 2);
			crawl(i * 2 + 2, (l + r) / 2, r);
		}
	}
	void crawl(){
		crawl(0, 0, n);
	}
	
	void show_array(){
		for(int i = 0; i < n; i++){
			cout << range_get<SUM>(0, 0, n, i, i + 1) << (i == n - 1 ? '\n' : ' ');
		}
	}
private:
	static constexpr char CHMOD = 0;
	static constexpr char UPDATE = 1;
	static constexpr char SUM = 10;
	
	template <char TYPE>
	void range_apply(int i, int il, int ir, int l, int r, int64_t g) {
		if (ir <= l || r <= il || break_condition<TYPE>(i, g)) {
			// break;
		} else if (l <= il && ir <= r && tag_condition<TYPE>(i, g)) {
			tag<TYPE>(i, g);
		} else {
			pushdown(i);
			range_apply<TYPE>(i * 2 + 1, il, (il + ir) / 2, l, r, g);
			range_apply<TYPE>(i * 2 + 2, (il + ir) / 2, ir, l, r, g);
			update(i);
		}
	}
	
	template <char TYPE>
	inline bool break_condition(int i, int64_t g) {
		switch (TYPE) {
			case CHMOD: return a[i].max < g;
			case UPDATE: return false;
			default: assert(false);
		}
	}
	
	template <char TYPE>
	inline bool tag_condition(int i, int64_t g) {
		switch (TYPE) {
			case CHMOD: return a[i].min == a[i].max;
			case UPDATE: return true;
			default: assert(false);
		}
	}
	
	template <char TYPE>
	inline void tag(int i, int64_t g) {
		int length = n >> (32 - __builtin_clz(i + 1) - 1);
		if (TYPE == CHMOD) {	
			tag<UPDATE>(i, a[i].max % g);
		} else if (TYPE == UPDATE) {
			a[i].max = g;
			a[i].maxc = length;
			a[i].min = g;
			a[i].lazy_update = g;
			a[i].sum = g * length;
		} else {
			assert(false);
		}
	}
	
	void pushdown(int i) {
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		// update
		if (a[i].lazy_update != INT64_MAX) {
			tag<UPDATE>(l, a[i].lazy_update);
			tag<UPDATE>(r, a[i].lazy_update);
			a[i].lazy_update = INT64_MAX;
		}
	}
	
	void update(int i) {
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		// min
		a[i].min = min(a[l].min, a[r].min);
		// max
		a[i].max = max(a[l].max, a[r].max);
		a[i].maxc = (a[i].max == a[l].max ? a[l].maxc : 0) + (a[i].max == a[r].max ? a[r].maxc : 0);
		// update
		a[i].lazy_update = INT64_MAX;
		// sum
		a[i].sum = a[l].sum + a[r].sum;
	}
	
	template <char TYPE>
	int64_t range_get(int i, int il, int ir, int l, int r) {
		// cout << "RANGE_GET " << TYPE << ' ' << i << ' ' << il << ' ' << ir << ' ' << l << ' ' << r << '\n';
		if(ir <= l || r <= il) {
			switch(TYPE) {
				case SUM: return 0;
				default: assert(false);
			}
		} else if (l <= il && ir <= r) {
			// base
			switch (TYPE) {
				case SUM: return a[i].sum;
				default: assert(false);
			}
		} else {
			pushdown(i);
			int64_t value_l = range_get<TYPE>(i * 2 + 1, il, (il + ir) / 2, l, r);
			int64_t value_r = range_get<TYPE>(i * 2 + 2, (il + ir) / 2, ir, l, r);
			// mult
			switch (TYPE) {
				case SUM: return value_l + value_r;
				default: assert(false);
			}
		}
	}
};

int main(){
	// IOS;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	segment_tree st(a, a + n);
	for(int i = 0; i < m; i++){
		ll t, l, r, k, x;
		cin >> t;
		switch(t){
			case 1:
				cin >> l >> r; l--;
				cout << st.range_sum(l, r) << '\n';
				break;
			case 2:
				cin >> l >> r >> x; l--;
				st.range_chmod(l, r, x);
				break;
			case 3:
				cin >> k >> x; k--;
				st.point_update(k, x); 
				break;
			default:
				assert(false);
		}
	}
}