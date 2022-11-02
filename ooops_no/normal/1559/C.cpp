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
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        if (*min_element(a.begin(), a.end()) == 1){
            cout << n + 1 << ' ';
            for (int i = 1; i <= n; i++){
                cout << i << ' ';
            }
            cout << endl;
            continue;
        }
        for (int i = n - 1; i >= 0; i--){
            if (a[i] == 0){
                for (int j = 1; j <= i + 1; j++){
                    cout << j << ' ';
                }
                cout << n + 1 << ' ';
                for (int j = i + 2; j <= n; j++){
                    cout << j << ' ';
                }
                break;
            }
        }
        cout << endl;
    }
    return 0;
}