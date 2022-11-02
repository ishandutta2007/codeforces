#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<char, int>> ans;
    ans.pb({'L', 2});
    ans.pb({'L', 2});
    ans.pb({'L', 2});
    n += 3;
    ans.pb({'R', 2});
    n += n - 2;
    ans.pb({'R', n - 1});
    cout << ans.size() << endl;
    for (auto to : ans){
        cout << to.first << " " << to.second << endl;
    }
    return 0;
}