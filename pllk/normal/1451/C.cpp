#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int c1[128] {};
        int c2[128] {};
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        for (auto c : a) c1[c]++;
        for (auto c : b) c2[c]++;
        for (char c = 'a'; c <= 'z'; c++) {
            int m = min(c1[c],c2[c]);
            c1[c] -= m;
            c2[c] -= m;
        }
        string ua, ub;
        for (char c = 'a'; c <= 'z'; c++) {
            for (int j = 0; j < c1[c]; j++) ua += c;
            for (int j = 0; j < c2[c]; j++) ub += c;
        }
        bool f = false;
        if (ua.size()%k != 0) f = true;
        int z = ua.size();
        for (int i = 0; i < z; i++) {
            if (ua[i] > ub[i]) f = true;
            if (i%k != 0 && ua[i-1] != ua[i]) f = true;
            if (i%k != 0 && ub[i-1] != ub[i]) f = true;
        }
        if (f) cout << "NO\n";
        else cout << "YES\n";
    }
}