#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int bl = 500;

struct Query
{
	int l, r, i;
	const bool operator<(const Query& a) {
		return (((l / bl) < (a.l / bl)) || ((l / bl) == (a.l / bl) && r < a.r));	 
	}
};

int ma[1000000] = {};
int ec[1000000] = {};
int pref_3_arr[1000000][3] = {};
std::vector<int> freq_array(3000000, 0);
std::vector<int> array_sorted;
int k;
int ans1 = 0;

void add(int i, bool isLeft) {
	if (isLeft) {
		ans1 += freq_array[pref_3_arr[i][2]];
		freq_array[pref_3_arr[i][0]]++;
	} else {
		ans1 += freq_array[pref_3_arr[i][1]];
		freq_array[pref_3_arr[i][0]]++;
	}
}

void rem(int i, bool isLeft) {
	if (isLeft) {
		freq_array[pref_3_arr[i][0]]--;
		ans1 -= freq_array[pref_3_arr[i][2]];
	} else {
		freq_array[pref_3_arr[i][0]]--;
		ans1 -= freq_array[pref_3_arr[i][1]];
	}
}

int answer(Query q) {
	return ans1;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	cin >> k;
	vector<int> t(n); for (int o = 0; o < n; o++) { cin >> t[o]; }
	int prefix_array[n] = {};
	std::map<int, int> map_to_pref_array;
	for (int i = 1; i <= n; ++i) {
		if (t[i - 1] == 1) cin >> ma[i]; 
		else cin >> ec[i]; 
		prefix_array[i] = prefix_array[i - 1] + (ma[i] - ec[i]);
		array_sorted.pb(prefix_array[i]);
		array_sorted.pb(prefix_array[i] - k);
		array_sorted.pb(prefix_array[i] + k);
	}
	array_sorted.pb(0);
	array_sorted.pb(-k);
	array_sorted.pb(k);
	sort(array_sorted.begin(), array_sorted.end());
	auto b = unique(array_sorted.begin(), array_sorted.end());
	auto y = array_sorted.begin();
	int ppp = 0;
	for (auto it = y; it != b; ++it) {
		map_to_pref_array[*it] = it - y + 1;
		ppp++;
	}
	for (int i = 0; i <= n; ++i) {
		pref_3_arr[i][0] = map_to_pref_array[prefix_array[i]];
		pref_3_arr[i][1] = map_to_pref_array[prefix_array[i] - k];
		pref_3_arr[i][2] = map_to_pref_array[prefix_array[i] + k];
	}
	int q; cin >> q;
	std::vector<Query> v(q);
	for (int i = 0; i < q; v[i].l--, ++i) cin >> v[i].l >> v[i].r, v[i].i = i;
	sort(v.begin(), v.end());
	int l = 1, r = 0;
	int ans[100004];
	for (int i = 0; i < q; ++i) 
	{
		while (r < v[i].r) add(++r, false);
		while (l > v[i].l) add(--l, true);
		while (r > v[i].r) rem(r--, false);
		while (l < v[i].l) rem(l++, true);
		ans[v[i].i] = answer(v[i]);
	}
	for (int i = 0; i < q; ++i) cout << ans[i] << "\n";
}