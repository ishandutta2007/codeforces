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
        string s, t;
        cin >> s >> t;
        int a = 0, b = -1e18, c = -1e18, d = -1e18;
        for (int i = 0; i < n; i++){
            if (s[i] == '0'){
                b = max(b, a);
                d = max(d, c);
            }
            else{
                c = max(c, a);
                d = max(d, b);
            }
            if (t[i] == '0'){
                b = max(b, a);
                d = max(d, c);
            }
            else{
                c = max(c, a);
                d = max(d, b);
            }
            a = max(a, d + 2);
            a = max(a, b + 1);
        }
        cout << a << endl;
    }
    return 0;
}