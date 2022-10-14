#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < a.size(); i++) {
            int sml = i;
            for (int j = a.size() - 1; j > i; j--) {
                if (a[sml] > a[j]) {
                    sml = j;
                }
            }
            if (sml == i) {
                continue;
            }
            swap(a[sml], a[i]);
            break;
        }
        
        if (a < b) {
            cout << a << "\n";
        } else {
            cout << "---\n";
        }
    }
}