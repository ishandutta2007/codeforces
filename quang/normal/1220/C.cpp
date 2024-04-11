#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

char s[N];
char smallest = 'z';

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (smallest < s[i]) {
            cout << "Ann\n";
        } else {
            cout << "Mike\n";
        }
        smallest = min(smallest, s[i]);
    }
    return 0;   
}