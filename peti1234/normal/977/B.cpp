#include <bits/stdc++.h>

using namespace std;
int n, maxi;
string s;
map<string, int> m;
int main()
{
    cin >> n >> s;
    for (int i=0; i<n-1; i++) {
        m[s.substr(i, 2)]++;
        maxi=max(maxi, m[s.substr(i, 2)]);
    }
    for (auto x:m) {
        if (x.second==maxi) {
            cout << x.first << "\n";
            return 0;
        }
    }
    return 0;
}