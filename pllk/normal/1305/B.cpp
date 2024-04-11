#include <iostream>
#include <vector>

using namespace std;

string s;
int n;
vector<int> v;

bool check(int k) {
    v.clear();
    vector<int> a, b;
    int h = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' && a.size() < k) {
            a.push_back(i+1);
            h = i;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == ')' && b.size() < k) {
            b.push_back(i+1);
            if (i < h) return false;
        }
    }
    if (a.size() < k || b.size() < k) return false;
    for (int i = 0; i < k; i++) v.push_back(a[i]);
    for (int i = k-1; i >= 0; i--) v.push_back(b[i]);
    return true;
}

int main() {
    cin >> s;
    n = s.size();
    for (int i = n; i >= 1; i--) {
        if (check(i)) {
            cout << "1\n";
            cout << v.size() << "\n";
            for (auto x : v) cout << x << " ";
            cout << "\n";
            return 0;
        }
    }
    cout << "0\n";
}