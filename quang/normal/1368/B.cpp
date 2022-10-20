#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long k;
    cin >> k;
    vector<int> res(10, 1);
    long long tot = 1;
    while (tot < k) {
        for (int i = 0; i < 10 && tot < k; i++) {
            tot /= res[i];
            res[i]++;
            tot *= res[i];
        }
    }   
    string u = "codeforces";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < res[i]; j++) {
            cout << u[i];
        }
    }
    cout << endl;
    return 0;
}