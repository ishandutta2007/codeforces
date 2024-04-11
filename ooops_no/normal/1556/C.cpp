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
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; i += 2){
        ans += min(c[i], c[i + 1]);
    }
    for (int i = 0; i < n; i++){
        if (i % 2 == 1) continue;
        int now_sum = 0, mn = 0;
        for (int j = i + 1; j < n; j++){
            if (j % 2 == 1) now_sum -= c[j];
            else now_sum += c[j];
            mn = min(mn, now_sum);
            if (now_sum + c[i] < 0) break;
            if (j % 2 == 0 && j + 1 < n){
                int first_val = c[i], second_val = c[j + 1];
                first_val += mn;
                int need_sum = now_sum + abs(mn);
                second_val -= need_sum;
                ans += max(0ll, min(first_val + 1, second_val + 1));
            }
        }
    }
    cout << ans << endl;
    return 0;
}