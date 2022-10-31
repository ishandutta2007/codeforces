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
 
using namespace std;
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
 
int sum = 0;
 
void sm(int a){
    for (int i = 0; i < a; i++){
        sum++;
    }
}
 
void sm1(int a){
    for (int i = 0; i > a; i--){
        sum--;
    }
}
 
void solve(){
    sum = 0;
    int a, b;
    cin >> a >> b;
    if (a < 0) sm1(a);
    else sm(a);
    if (b < 0) sm1(b);
    else sm(b);
    cout << sum << endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}