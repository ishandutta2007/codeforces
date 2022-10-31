#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
 
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
 
int mn = 100, mx = 0;
 
void check(int v){
            mn = 100, mx = 0;
    while(v > 0){
        mn = min(mn, v % 10);
        mx = max(mx, v % 10);
        v /= 10;
    }
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
        int a, n;
        cin >> a >> n;
        while(n > 1){
            check(a);
            if (mn == 0 || mx == 0) break;
            a += mn * mx;
            n--;
        }
        cout << a << endl;
	}
	return 0;
}