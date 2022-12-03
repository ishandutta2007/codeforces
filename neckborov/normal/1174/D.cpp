#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int topkek = 1 << n;
    vector<int> a;
    for (int i = 1; i < topkek; i++) {
        if (i < (i ^ x)) {
            a.push_back(i);
        }
    }
    cout << a.size() << endl;
    if (!a.empty()) {
        cout << a[0] << ' ';
    }
    for (int i = 1; i < a.size(); i++) {
        cout << (a[i] ^ a[i - 1]) << ' ';
    }
    return 0;
}