#include <iostream>
#include <vector>

using namespace std;

int t;
string s;

bool ok(int k) {
    if (12%k != 0) return false;
    for (int i = 0; i < 12/k; i++) {
        bool v = false;
        for (int j = i; j < 12; j += 12/k) {
            if (s[j] == 'O') v = true;
        }
        if (!v) return true;
    }
    return false;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        vector<int> v;
        for (int j = 1; j <= 12; j++) {
            if (ok(j)) v.push_back(j);
        }
        cout << v.size() << " ";
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << "x" << 12/v[j] << " ";
        }
        cout << endl;
    }
}