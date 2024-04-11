#include <iostream>

using namespace std;

string s;
int n, m;
int c[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    int u = 0;
    for (int i = 1; i <= n/2; i++) {
        u += c[i];
        if (u%2 == 1) swap(s[i-1], s[n-i]);
    }
    cout << s << "\n";
}