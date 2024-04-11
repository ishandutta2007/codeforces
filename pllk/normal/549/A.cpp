#include <iostream>

using namespace std;

int n, m;
string s[55];
int z;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            int c[256] = {0};
            c[s[i][j]]++;
            c[s[i+1][j]]++;
            c[s[i][j+1]]++;
            c[s[i+1][j+1]]++;
            if (c['f'] && c['a'] && c['c'] && c['e']) z++;
        }
    }
    cout << z << "\n";
}