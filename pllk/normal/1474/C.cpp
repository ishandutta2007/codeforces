#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> d;

bool check(int x, multiset<int> s) {
    d.clear();
    while (s.size()) {
        auto a = *s.rbegin();
        s.erase(s.find(a));
        int b = x-a;
        if (!s.count(b)) return false;
        s.erase(s.find(b));
        x = max(a,b);
        d.push_back({a,b});
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> s;
        vector<int> v;
        for (int i = 1; i <= 2*n; i++) {
            int x;
            cin >> x;
            s.insert(x);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        bool f = false;
        for (int i = 0; i < 2*n-1; i++) {
            int x = v[i]+v[2*n-1];
            f = check(x, s);
            if (f) {
                cout << "YES\n";
                cout << x << "\n";
                for (auto p : d) {
                    cout << p.first << " " << p.second << "\n";
                }
                break;
            }
        }
        if (!f) cout << "NO\n";
    }
}