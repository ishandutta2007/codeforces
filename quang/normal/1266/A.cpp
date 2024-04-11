#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int hasZero = 0, numEven = 0;
        int sum = 0;
        for (char u : s) {
            int id = u - '0';
            sum += id;
            hasZero |= (id == 0);
            numEven += (id % 2 == 0);
        }
        if (hasZero && numEven > 1 && sum % 3 == 0) {
            cout << "red\n";
        } else {
            cout << "cyan\n";
        }
    }
    return 0;
}