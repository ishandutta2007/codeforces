#include <bits/stdc++.h>
 
using namespace std;

typedef int ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> arr(n);
    string s;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ll curr = 0;
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == '.') ++curr;
            else curr = 0;
            if (curr >= k) ++ans;
        }
    }
    if (k > 1) {
        for (int i = 0; i < m; ++i) {
            ll curr = 0;
            for (int j = 0; j < n; ++j) {
                if (arr[j][i] == '.') ++curr;
                else curr = 0;
                if (curr >= k) ++ans;
            }
        }
    }
    cout << ans;
    //system("pause");
    return 0;
}