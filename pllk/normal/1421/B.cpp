#include <iostream>
#include <vector>

using namespace std;

int n;
string g[222];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> g[i];
        // 00 -> 11
        vector<pair<int,int>> v1;
        if (g[0][1] != '0') v1.push_back({1,2});
        if (g[1][0] != '0') v1.push_back({2,1});
        if (g[n-1][n-2] != '1') v1.push_back({n,n-1});
        if (g[n-2][n-1] != '1') v1.push_back({n-1,n});
        // 11 -> 00
        vector<pair<int,int>> v2;
        if (g[0][1] != '1') v2.push_back({1,2});
        if (g[1][0] != '1') v2.push_back({2,1});
        if (g[n-1][n-2] != '0') v2.push_back({n,n-1});
        if (g[n-2][n-1] != '0') v2.push_back({n-1,n});
        if (v2.size() <= 2) swap(v1,v2);
        cout << v1.size() << "\n";
        for (auto x : v1) {
            cout << x.first << " " << x.second << "\n";
        }
    }
}