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
#define int long long

mt19937 rnd(51);

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> ans, v(n);
	set<int> st;
	for (int i = 0; i < 2e5; i++){
        st.insert(i);
	}
	map<int,int> used;
	for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v[i] = a;
        used[a]++;
        st.erase(a);
	}
	for (int i = 0; i < n; i++){
        ans.pb(*st.begin());
        st.erase(st.begin());
        used[v[i]]--;
        if (used[v[i]] == 0){
            st.insert(v[i]);
        }
	}
	for (auto to : ans){
        cout << to << " ";
	}
	return 0;
}