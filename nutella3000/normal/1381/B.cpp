#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for(int i = 0;i < 2 * n;i++) cin >> a[i];

        vector<bool> used(2 * n + 1);
        int Min = 2 * n;
        vector<int> num;
        int last = 2 * n;

        for(int i = 2 * n - 1;i >= 0;i--) {
            if (a[i] != Min) continue;
            num.emplace_back(last - i);

            for(int j = i;j < last;j++) used[a[j]] = true;
            last = i;
            while(used[Min]) Min--;
        }

        for(int i = 1;i <= 2 * n;i++) used[i] = false;
        used[0] = true;

        for(int i : num) {
            for(int j = 2 * n - i;j >= 0;j--) {
                if (used[j]) used[j + i] = true;
            }
        }

        if (used[n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}