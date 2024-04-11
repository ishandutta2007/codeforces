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
	vector<int> a(n), b(n);
	vector<int> ind(n + 1), ind1(n + 1);
	for (int i = 0; i < n; i++){
        cin >> a[i];
        ind[a[i]] = i;
	}
	for (int i = 0; i < n; i++){
        cin >> b[i];
        ind1[b[i]] = i;
	}
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
        if (ind[i] < ind1[i]){
            mp[ind1[i] - ind[i]]++;
        }
        else{
            mp[ind1[i] + n - ind[i]]++;
        }
	}
	int mx = 0;
	for (auto to : mp){
        mx = max(mx, to.second);
	}
	cout << mx << endl;
	return 0;
}