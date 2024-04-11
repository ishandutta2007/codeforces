#include <bits/stdc++.h>

using namespace std;

int main() { 
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        vector<bool> used(n);
        for (int j = 0; j < k; ++j) {
            int temp;
            cin >> temp;
            used[temp - 1] = true;
        }
        int ans = 1;
        while (true) {
            bool cr = true;
            for (int j = 0; j < n; ++j)
                cr = cr && used[j];
            if (cr == true) break;
            vector<bool> newarr(n);
            for (int j = 0; j < n; ++j) {
                if (j > 0 && used[j - 1]) newarr[j] = true;
                if (j < n - 1 && used[j + 1]) newarr[j] = true;
                if (used[j]) newarr[j] = true;
            }
            used = newarr;
            ++ans;
        }
        cout << ans << '\n';
    }
    //system("pause");
    return 0; 
}