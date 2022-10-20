#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    auto ask = [](int u) {
        cout << "? " << u << endl;
        int res;
        cin >> res;
        return res;
    };

    int low = 1, high = n;
    while (high - low >= 1) {
        int mid1 = low + high >> 1;
        int mid2 = mid1 + 1;
        int u = ask(mid1);
        int v = ask(mid2);
        if (u < v) {
            high = mid1;
        } else {
            low = mid2;
        }
    }
    cout << "! " << low << endl;
    return 0;
}