#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
//#include<unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double

mt19937 rnd(51);

const int N = 1e7 + 10;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> need(N);
	vector<pair<int,int>> ans(N);
	vector<int> last(N);
	vector<int> v;
	for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.pb(a);
        need[a] = 1;
	}
	for (int i = 2; i < N; i++){
        for (int j = i; j < N; j += i){
            if (need[j]){
            if (ans[j].first == 0){
                if (last[j] == 0){
                    last[j] = i;
                }
                if (__gcd(j, last[j] + i) == 1 && i % last[j] != 0){
                    ans[j] = {last[j], i};
                }
            }
            }
        }
	}
	for (auto to : v){
	    if (ans[to].first == 0) cout << -1 << " ";
        else cout << ans[to].first << " ";
	}
	cout << endl;
	for (auto to : v){
	    if (ans[to].second == 0) cout << -1 << " ";
        else cout << ans[to].second << " ";
	}
	return 0;
}