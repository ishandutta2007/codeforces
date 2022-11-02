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
#define int long long
#define ll long long

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
        vector<int> a(n), col(30);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            for (int j = 0; j < 30; j++){
                if (a[i] & (1 << j)){
                    col[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 30; i++){
            if (col[i] == n){
                ans += (1 << i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}