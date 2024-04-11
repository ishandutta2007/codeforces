#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

template <typename T, class Compare = std::less<T>> class RangeMinQuery : private Compare {
	static const int BUCKET_SIZE = 32;
	static const int BUCKET_SIZE_LOG = 5;
	static_assert(BUCKET_SIZE == (1 << BUCKET_SIZE_LOG), "BUCKET_SIZE should be a power of 2");
	static const int CACHE_LINE_ALIGNMENT = 64;
	int n = 0;
	std::vector<T> data;
	std::vector<T> pref_data;
	std::vector<T> suff_data;
	std::vector<T> sparse_table;
	std::vector<uint32_t> range_mask;
private:
	int num_buckets() const {
		return n >> BUCKET_SIZE_LOG;
	}
	int num_levels() const {
		return num_buckets() ? 32 - __builtin_clz(num_buckets()) : 0;
	}
	int sparse_table_size() const {
		return num_buckets() * num_levels();
	}
private:
	const T& min(const T& a, const T& b) const {
		return Compare::operator()(a, b) ? a : b;
	}
	void setmin(T& a, const T& b) const {
		if (Compare::operator()(b, a)) a = b;
	}

	template <typename Vec> static int get_size(const Vec& v) { using std::size; return int(size(v)); }
public:
	RangeMinQuery() {}
	template <typename Vec> explicit RangeMinQuery(const Vec& data_, const Compare& comp_ = Compare())
		: Compare(comp_)
		, n(get_size(data_))
		, data(n)
		, pref_data(n)
		, suff_data(n)
		, sparse_table(sparse_table_size())
		, range_mask(n)
	{
		for (int i = 0; i < n; i++) data[i] = data_[i];
		for (int i = 0; i < n; i++) {
			if (i & (BUCKET_SIZE-1)) {
				uint32_t m = range_mask[i-1];
				while (m && !Compare::operator()(data[(i | (BUCKET_SIZE-1)) - __builtin_clz(m)], data[i])) {
					m -= uint32_t(1) << (BUCKET_SIZE - 1 - __builtin_clz(m));
				}
				m |= uint32_t(1) << (i & (BUCKET_SIZE - 1));
				range_mask[i] = m;
			} else {
				range_mask[i] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			pref_data[i] = data[i];
			if (i & (BUCKET_SIZE-1)) {
				setmin(pref_data[i], pref_data[i-1]);
			}
		}
		for (int i = n-1; i >= 0; i--) {
			suff_data[i] = data[i];
			if (i+1 < n && ((i+1) & (BUCKET_SIZE-1))) {
				setmin(suff_data[i], suff_data[i+1]);
			}
		}
		for (int i = 0; i < num_buckets(); i++) {
			sparse_table[i] = data[i * BUCKET_SIZE];
			for (int v = 1; v < BUCKET_SIZE; v++) {
				setmin(sparse_table[i], data[i * BUCKET_SIZE + v]);
			}
		}
		for (int l = 0; l+1 < num_levels(); l++) {
			for (int i = 0; i + (1 << (l+1)) <= num_buckets(); i++) {
				sparse_table[(l+1) * num_buckets() + i] = min(sparse_table[l * num_buckets() + i], sparse_table[l * num_buckets() + i + (1 << l)]);
			}
		}
	}

	T query(int l, int r) const {
		assert(l <= r);
		int bucket_l = (l >> BUCKET_SIZE_LOG);
		int bucket_r = (r >> BUCKET_SIZE_LOG);
		if (bucket_l == bucket_r) {
			uint32_t msk = range_mask[r] & ~((uint32_t(1) << (l & (BUCKET_SIZE-1))) - 1);
			int ind = (l & ~(BUCKET_SIZE-1)) + __builtin_ctz(msk);
			return data[ind];
		} else {
			T ans = min(suff_data[l], pref_data[r]);
			bucket_l++;
			if (bucket_l < bucket_r) {
				int level = (32 - __builtin_clz(bucket_r - bucket_l)) - 1;
				setmin(ans, sparse_table[level * num_buckets() + bucket_l]);
				setmin(ans, sparse_table[level * num_buckets() + bucket_r - (1 << level)]);
			}
			return ans;
		}
	}
};
template <typename T> using RangeMaxQuery = RangeMinQuery<T, std::greater<T>>;


ll sq(ll x) { return x * x; }

int n, prv[MAXN], nxt[MAXN];
ll d[MAXN], c[MAXN], A;
ll cost[MAXN], sum[MAXN];

void solve() {
    cin >> n >> A;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> c[i];
        c[i] = A - c[i];
        ans = max(ans, c[i]);
    }
    for (int i = 0; i < n-1; i++) cost[i] = sq(d[i+1] - d[i]);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = c[i];
        sum[i + 1] += sum[i];
    }

    RangeMaxQuery<ll> q_max(vector<ll>(sum, sum + n + 1));
    RangeMinQuery<ll> q_min(vector<ll>(sum, sum + n + 1));

    vector<int> one;
    for (int i = 0; i < n-1; i++) {
        while (sz(one) && cost[one.back()] <= cost[i]) one.pop_back();
        prv[i] = (sz(one) ? one.back() : -1);
        one.push_back(i);
    }
    vector<int> two;
    for (int i = n-2; i >= 0; i--) {
        while (sz(two) && cost[two.back()] <= cost[i]) two.pop_back();
        nxt[i] = (sz(two) ? two.back() : n-1);
        two.push_back(i);
    }
    for (int i = 0; i < n-1; i++) {
        // i can't have the (prv[i], prv[i]+1) gap as well as the (nxt[i], nxt[i]+1) gap
        int L = prv[i]+1, R = nxt[i];
        ll left = 0, right = 0;
        if (L < i) {
            left = max(left, sum[i] - q_min.query(L, i - 1));
            // for (int j = L; j < i; j++) left = max(left, sum[i - 1] - (j ? sum[j - 1] : 0));
        }
        if (i + 1 <= R) {
            right = max(right, -sum[i + 1] + q_max.query(i + 2, R + 1));
            // for (int j = i + 1; j <= R; j++) right = max(right, sum[j] - sum[i]);
        }
        ans = max(ans, left + right + c[i] - cost[i]);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}