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
    int now = 6;
    vector<pair<int,int>> ans;
    ans.pb({3, 5});
    while(n > 1){
        ans.pb({3, now});
        ans.pb({3, now + 1});
        ans.pb({2, now});
        ans.pb({2, now + 1});
        ans.pb({4, now});
        ans.pb({4, now + 1});
        ans.pb({3, now + 2});
        ans.pb({3, now + 3});
        now += 4;
        n -= 2;
    }
    if (n == 1){
        ans.pb({3, now});
        ans.pb({2, now});
        ans.pb({4, now});
        ans.pb({3, now + 1});
        ans.pb({5, now});
        ans.pb({5, now + 1});
        ans.pb({5, now + 2});
        ans.pb({3, now + 2});
        ans.pb({4, now + 2});
        ans.pb({1, now});
        ans.pb({3, 4});
        ans.pb({2, 4});
        ans.pb({1, 4});
        ans.pb({0, 4});
        ans.pb({0, now});
        for (int i = 5; i < now; i++){
            ans.pb({0, i});
        }
    }
    else{
        now--;
        ans.pb({3, 4});
        ans.pb({2, now});
        ans.pb({2, 4});
        ans.pb({1, 4});
        ans.pb({1, now});
        ans.pb({0, now});
        ans.pb({0, 4});
        for (int i = 5; i < now; i++){
            ans.pb({0, i});
        }
    }
    cout << ans.size() << endl;
    for (auto to  : ans){
        cout << to.first << " " << to.second << endl;
    }
    return 0;
}