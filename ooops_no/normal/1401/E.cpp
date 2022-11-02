#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
#include<unordered_set>

using namespace std;

/*

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;

*/
/*

st.find_by_order();
st.order_of_key();

*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

//  ,    

const int N = 1e6 + 10;
int t[4 * N];

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 1;
    vector<pair<int, pair<int, int>>> v, v1;
    for (int i = 0; i < n; i++){
        int aa, x, y;
        cin >> aa >> x >> y;
        if (x == 0 && y == 1e6){
            ans++;
        }
        if (x == 0){
            v.pb({y + 1, {aa, 0}});
            update(1, 0, N - 1, aa, 1);
        }
        else{
            v1.pb({x - 1, {aa, 0}});
        }
    }
    sort(v.begin(), v.end());
    sort(v1.rbegin(), v1.rend());
    vector<pair<int, pair<int,int>>> a;
    int cnt = 0;
    for (int i = 0; i < m; i++){
        int aa, x, y;
        cin >> aa >> x >> y;
        a.pb({aa, {min(x, y), max(x, y)}});
        if (min(x, y) == 0 && max(x, y) == 1e6){
            cnt++;
        }
    }
    if (n == 0){
        for (int j = 0; j < m; j++){
            if (a[j].second.first == 0 && a[j].second.second == 1e6){
                ans++;
            }
        }
        cout << ans << endl;
        return 0;
    }
    else if (m == 0){
        cout << ans << endl;
        return 0;
    }
    ans += cnt;
    sort(a.begin(), a.end());
    int j = 0;
    for (int i = 0; i < a.size(); i++){
        while(j < v.size() && v[j].first <= a[i].first){
            update(1, 0, N - 1, v[j].second.first, v[j].second.second);
            j++;
        }
        ans += sum(1, 0, N - 1, a[i].second.first, a[i].second.second);
    }
    for (int i = 0; i < 4 * N; i++){
        t[i] = 0;
    }
    for (auto to : v1){
        update(1, 0, N - 1, to.second.first, 1);
    }
    j = 0;
    for (int i = a.size() - 1; i > -1; i--){
        while(j < v1.size() && v1[j].first >= a[i].first){
            update(1, 0, N - 1, v1[j].second.first, v1[j].second.second);
            j++;
        }
        ans += sum(1, 0, N - 1, a[i].second.first, a[i].second.second);
    }
    cout << ans << endl;
    return 0;
}