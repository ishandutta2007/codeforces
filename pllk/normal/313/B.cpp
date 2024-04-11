#include <iostream>

using namespace std;

string s;
int m;
int l, r;

int t[200000];

int main() {
    cin >> s;
    int p = s.length();
    for (int i = 0; i < p-1; i++) {
        if (i > 0) t[i] += t[i-1];
        if (s[i] == s[i+1]) t[i]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        r--; l--;
        int v = 0;
        if (r > 0) v += t[r-1];
        if (l > 0) v -= t[l-1];
        cout << v << endl;
    }
}