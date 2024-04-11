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
        vector<int> v(n);
        vector<int> a, b;
        for (int i = 0; i < n; i++){
            char c;
            cin >> c;
            v[i] = c - '0';
            if (i < n / 2 && v[i] == 0) a.pb(i);
            else if (v[i] == 0) b.pb(i);
        }
        if (a.size() + b.size() == 0){
            cout << 1 << ' ' << n / 2 << ' ' << 2 << ' ' << n / 2 + 1 << endl;
        }
        else{
            if (a.size() > 0){
                cout << a[0] + 1 << ' ' << n << ' ' << a[0] + 2 << ' ' << n << endl;
            }
            else{
                cout << 1 << ' ' << b[0] + 1 << ' ' << 1 << ' ' << b[0] << endl;
            }
        }
    }
    return 0;
}