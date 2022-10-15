#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        s += "0";
        vector<int> v;
        int u = 0;
        for (auto c : s) {
            if (c == '1') u++;
            else {
                if (u != 0) v.push_back(u);
                u = 0;
            }
        }
        sort(v.begin(),v.end());
        int k = v.size()-1;
        int t = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i%2 == k%2) t += v[i];
        }
        cout << t << "\n";
    }
}