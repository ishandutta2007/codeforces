#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string u = s;
        sort(u.begin(), u.end());
        int c = 0;
        for (int i = 0; i < n; i++) if (s[i] != u[i]) c++;
        cout << c << "\n";
    }
}