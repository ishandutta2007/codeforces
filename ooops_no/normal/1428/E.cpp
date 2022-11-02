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


int check(int val, int p){
    int v = val / p;
    int u = val - v * p;
    return (p - u) * v * v + (v + 1) * (v + 1) * u;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    multiset<pair<int, pair<int,int>>> st;
    int sum = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum += a * a;
        if (a == 1){
            continue;
        }
        st.insert({check(a, 1) - check(a, 2), {a, 2}});
    }
    for (int i = 0; i < k - n; i++){
        auto v = *st.rbegin();
        sum -= v.first;
        st.erase(st.find(v));
        if (v.second.first <= v.second.second){
            continue;
        }
        else{
            st.insert({check(v.second.first, v.second.second) - check(v.second.first, v.second.second + 1), {v.second.first, v.second.second + 1}});
        }
    }
    cout << sum << endl;
    return 0;
}