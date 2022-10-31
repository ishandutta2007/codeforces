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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> st;

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

const int N = 4e5 + 10;
int t[4 * N];

void update(int v, int tl, int tr, int pos, int new_val) {
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
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    set<int> stt;
    map<int,int> ind;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
        stt.insert(abs(b));
    }
    int j = 0;
    for (auto to : stt){
        ind[to] = j;
        j++;
    }
    int cnt = 0;
    set<int> lol;
    for (int i = 0; i < n; i++){
        if (v[i].first == 1){
            if (v[i].second < 0){
                cnt--;
                update(1, 0, N - 1, ind[abs(v[i].second)], 0);
                st.erase(abs(v[i].second));
                lol.erase(abs(v[i].second));
            }
            else{
                cnt++;
                update(1, 0, N - 1, ind[abs(v[i].second)], v[i].second);
                st.insert(abs(v[i].second));
                lol.insert(abs(v[i].second));
            }
        }
        else{
            if (v[i].second < 0){
                update(1, 0, N - 1, ind[abs(v[i].second)], 0);
                st.erase(abs(v[i].second));
            }
            else{
                update(1, 0, N - 1, ind[abs(v[i].second)], v[i].second);
                st.insert(abs(v[i].second));
            }
        }
        if (st.size() == 0){
            cout << 0 << endl;
            continue;
        }
        if (cnt == (int)st.size()){
            int ans = sum(1, 0, N - 1, 0, N - 1) * 2;
            ans -= *st.begin();
            cout << ans << endl;
        }
        else{
            if (cnt == 0){
                cout << sum(1, 0, N - 1, 0, N - 1) << endl;
            }
            else{
                int j = st.size() - cnt;
                int el = *st.find_by_order(j);
                if (*lol.begin() < el){
                    cout <<  sum(1, 0, N - 1, ind[el], N - 1) * 2 + sum(1, 0, N - 1, 0, ind[*st.find_by_order(j - 1)]) << endl;
                }
                else{
                    int f = sum(1, 0, N - 1, ind[el], N - 1);
                    int s = sum(1, 0, N - 1, 0, ind[*st.find_by_order(j - 1)]);
                    int ans = f * 2 - *lol.begin() + s;
                    if (1){
                        ans += *st.find_by_order(j - 1);
                    }
                    cout << ans << endl;
                }
            }
        }
    }
    return 0;
}