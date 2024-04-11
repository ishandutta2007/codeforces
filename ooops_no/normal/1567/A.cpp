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
        string s;
        cin >> s;
        for (int i = 0; i < n; i++){
            if (s[i] == 'U'){
                cout << 'D';
            }
            if (s[i] == 'D'){
                cout << 'U';
            }
            if (s[i] == 'L'){
                cout << 'L';
            }
            if (s[i] == 'R'){
                cout << 'R';
            }
        }
        cout << endl;
    }
    return 0;
}