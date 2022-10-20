#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        int maxVal = 0;
        for (int &u : a) {
            cin >> u;
            sum += u;
            maxVal = max(maxVal, u);
        }
        if (2 * maxVal > sum) {
            cout << "T\n";
            continue;
        }
        if (sum % 2 == 0) cout << "HL\n";
        else cout << "T\n";
    }   
    return 0;
}