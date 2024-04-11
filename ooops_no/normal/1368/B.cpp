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
    int mn = 1;
    vector<int> v(10, 1);
    while(mn < n){
        int j = 0;
        for (int i = 0; i < 10; i++){
            if (v[i] < v[j]){
                j = i;
            }
        }
        mn /= v[j];
        v[j]++;
        mn *= v[j];
    }
    for (int i = 0; i < v[0]; i++){
        cout << 'c';
    }
    for (int i = 0; i < v[1]; i++){
        cout << 'o';
    }
    for (int i = 0; i  < v[2]; i++){
        cout << 'd';
    }
    for (int i = 0; i < v[3]; i++){
        cout << 'e';
    }
    for (int i = 0; i < v[4]; i++){
        cout << 'f';
    }
    for (int i = 0; i < v[5]; i++){
        cout << 'o';
    }
    for (int i = 0; i < v[6]; i++){
        cout << 'r';
    }
    for (int i = 0; i < v[7]; i++){
        cout << 'c';
    }
    for (int i =0 ; i < v[8]; i++){
        cout << 'e';
    }
    for (int i = 0; i < v[9]; i++){
        cout << 's';
    }
    return 0;
}