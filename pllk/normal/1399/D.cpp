#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v0, v1;
        vector<int> r;
        int k = 0;
        for (auto c : s) {
            if (c == '0') {
                if (v1.size()) {
                    int u = v1.back();
                    v1.pop_back();
                    r.push_back(u);
                    v0.push_back(u);
                } else {
                    v0.push_back(++k);
                    r.push_back(k);
                }
            }
            if (c == '1') {
                if (v0.size()) {
                    int u = v0.back();
                    v0.pop_back();
                    r.push_back(u);
                    v1.push_back(u);
                } else {
                    v1.push_back(++k);
                    r.push_back(k);
                }
            }
        }
        cout << k << "\n";
        for (auto x : r) cout << x << " ";
        cout << "\n";
    }
}