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

bool prime(int v){
    if (v == 1) return 0;
    for (int i = 2; i * i <= v; i++){
        if (v % i == 0){
            return 0;
        }
    }
    return 1;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (!prime(s[i] - '0')){
            cout << 1 << endl << s[i] << endl;
            return;
        }
    }
    for (int i = 0; i < s.size(); i++){
        for (int j = i + 1; j < s.size(); j++){
            if (!prime((s[i] - '0') * 10 + s[j] - '0')){
                cout << 2 << endl << s[i] << s[j] << endl;
                return;
            }
        }
    }
}

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
        solve();
    }
    return 0;
}