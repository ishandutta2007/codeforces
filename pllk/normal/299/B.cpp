#include <iostream>

using namespace std;

int n, k;
string s;
int t[500000];
int maxi;

int main() {
    cin >> n >> k;
    cin >> s;
    maxi = 0;
    t[0] = 1;
    for (int i = 0; i < n; i++) {
        if (!t[i]) continue;
        int a = i+k;
        if (a >= n) a = n-1;
        for (int j = a; j > maxi && j > i; j--) {
            if (s[j] == '.') t[j] = 1;
        }
        maxi = a;
    }
    if (t[n-1]) cout << "YES\n";
    else cout << "NO\n";
}