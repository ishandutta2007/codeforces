#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int c, d;
        cin >> c >> d;
        if (c == 0 && d == 0){
            cout << 0 << endl;
        }
        else if (c == d){
            cout << 1 << endl;
        }
        else{
            if (abs(c - d) % 2 == 0){
                cout << 2 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}