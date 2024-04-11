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

const int MOD = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, now = 24, last = 6;
    cin >> n;
    vector<int> ans((int)1e6 + 10);
    ans[3] = 2;
    for (int i = 4; i <= n; i++){
        ans[i] = ((now - last * 2 + ans[i - 1] * 2) % MOD + MOD * MOD) % MOD;
        now = ((i + 1) * now) % MOD;
        last = last * i % MOD;
    }
    cout << (ans[n] + MOD * MOD) % MOD;
    return 0;
}