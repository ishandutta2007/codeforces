#include <iostream>

using namespace std;

int n;
string s;
int c[128];

int main() {
    cin >> n;
    cin >> s;
    if (n%4 != 0) {
        cout << "===\n";
        return 0;
    }
    for (int i = 0; i < n; i++) c[s[i]]++;
    if (c['A'] > n/4 || c['C'] > n/4 || c['G'] > n/4 || c['T'] > n/4) {
        cout << "===\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (c['A'] < n/4) {s[i] = 'A'; c['A']++;}
            else if (c['C'] < n/4) {s[i] = 'C'; c['C']++;}
            else if (c['G'] < n/4) {s[i] = 'G'; c['G']++;}
            else if (c['T'] < n/4) {s[i] = 'T'; c['T']++;}
        }
    }
    cout << s << "\n";
}