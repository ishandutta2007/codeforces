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
        string s;
        cin >> s;
        vector<int> a;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '0'){
                a.pb(i);
            }
        }
        if (a.size() == 0){
            cout << 0 << endl;
        }
        else{
            bool x = 1;
            for (int i = 1; i < a.size(); i++){
                if (a[i - 1] + 1 != a[i]){
                    x = 0;
                }
            }
            if (x){
                cout << 1 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }
    }
    return 0;
}