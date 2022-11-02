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
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            string s = "";
            for (int j = 0; j < i; j++){
                s += '(';
            }
            for (int j = 0; j < i; j++){
                s += ')';
            }
            for (int j = 0; j < n - i; j++){
                s += '(';
                s += ')';
            }
            cout << s << endl;
        }
    }
    return 0;
}