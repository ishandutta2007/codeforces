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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            if (i == j){
                lcp[i][j] = n - i;
            }
            else{
                lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
            }
        }
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++){
        dp[i] = n - i;
        for (int j = 0; j < i; j++){
            if (lcp[i][j] < n - i){
                if (s[lcp[i][j] + i] > s[lcp[i][j] + j]){
                    dp[i] = max(dp[i], dp[j] + (n - i) - lcp[i][j]);
                }
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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