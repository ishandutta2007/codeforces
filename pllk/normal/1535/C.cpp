#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int r1 = 0, r2 = 0;
        ll c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i]-'0' == i%2 || s[i] == '?') r1++;
            else r1 = 0;
            if (s[i]-'0' == (i+1)%2 || s[i] == '?') r2++;
            else r2 = 0;
            c += max(r1,r2);
        }
        cout << c << "\n";
    }
}