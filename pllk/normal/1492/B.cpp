#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n+1];
        for (int i = 1; i <= n; i++) cin >> p[i];
        set<int> s;
        for (int i = 1; i <= n; i++) s.insert(i);
        vector<int> v;
        for (int i = n; i >= 1; i--) {
            bool f = false;
            if (p[i] == *s.rbegin()) f = true;
            s.erase(p[i]);
            v.push_back(p[i]);
            if (f) {
                reverse(v.begin(), v.end());
                for (auto x : v) cout << x << " ";
                v.clear();
                if (s.empty()) break;
            }
        }
        cout << "\n";
    }
}