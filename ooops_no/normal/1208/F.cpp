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

const int N = (1 << 21);
vector<int> dp(N), dpp(N);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dpp[a[i]] = dp[a[i]];
        dp[a[i]] = i;
    }
    for (int i = 0; i < 21; i++){
        for (int j = 0; j < N; j++){
            if (!(j & (1 << i))){
                if (dpp[j | (1 << i)] > dpp[j]){
                    dpp[j] = dpp[j | (1 << i)];
                }
                if (dp[j] < dpp[j]){
                    swap(dpp[j], dp[j]);
                }
                if (dp[j | (1 << i)] > dpp[j]){
                    dpp[j] = dp[j | (1 << i)];
                }
                if (dp[j] < dpp[j]){
                    swap(dpp[j], dp[j]);
                }
            }
        }
    }
    int anss = 0;
    for (int i = 0; i + 2 < n; i++){
        int now = 0;
        for (int j = 20; j >= 0; j--){
            if (!(a[i] & (1 << j))){
                if (dpp[now + (1 << j)] > i){
                    now += (1 << j);
                }
            }
        }
        anss = max(anss, now + a[i]);
    }
    cout << anss << endl;
    return 0;
}