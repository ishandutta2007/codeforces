#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> dp1(n); //  
    vector<int> dp2(n); //  
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp1[i] = dp2[i] = 1;
        if (i > 0 && a[i] > a[i - 1]) {
            dp1[i] = max(dp1[i], dp1[i - 1] + 1);
            dp2[i] = max(dp2[i], dp2[i - 1] + 1);
        }
        if (i > 1 && a[i] > a[i - 2]) {
            dp2[i] = max(dp2[i], dp1[i - 2] + 1);
        }
        res = max(res, dp1[i]);
        res = max(res, dp2[i]);
    }
    cout << res << "\n";
    

    return 0;
}