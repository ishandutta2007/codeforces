#include <iostream>
#include <vector>

using namespace std;

int a[1111];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> v;
        for (int i = 1; i <= n; i += 2) {
            if (a[i] == a[i+1]) {
                v.push_back(a[i]);
                v.push_back(a[i+1]);
            } else {
                v.push_back(0);
            }
        }
        cout << v.size() << "\n";
        for (auto x : v) cout << x << " ";
        cout << "\n";
    }
}