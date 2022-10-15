#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back({x,y,z,i});
    }
    sort(a.begin(),a.end());
    vector<vector<int>> b;
    for (int i = 0; i < a.size(); i++) {
        b.push_back(a[i]);
        int k = b.size();
        if (k >= 2) {
            if (b[k-2][0] == b[k-1][0] && b[k-2][1] == b[k-1][1]) {
                cout << b[k-2][3] << " " << b[k-1][3] << "\n";
                b.pop_back();
                b.pop_back();
            }
        }
    }
    vector<vector<int>> c;
    for (int i = 0; i < b.size(); i++) {
        c.push_back(b[i]);
        int k = c.size();
        if (k >= 2) {
            if (c[k-2][0] == c[k-1][0]) {
                cout << c[k-2][3] << " " << c[k-1][3] << "\n";
                c.pop_back();
                c.pop_back();
            }
        }
    }
    for (int i = 0; i < c.size(); i += 2) {
        cout << c[i][3] << " " << c[i+1][3] << "\n";
    }
}