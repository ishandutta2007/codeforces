#include <cstring>
#include <iostream>

using namespace std;
const int N = 1e2;

char s[N][N];

int main() {
    int n{}, m{};
    cin >> n >> m;
    memset(s, '.', sizeof(s));
    for (int i = 1; i <= n; i += 2)
        for (int j = 1; j <= m; j++)
            s[i][j] = '#';
    for (int i = 2; i <= n; i += 2)
        if (i % 4 == 2)
            s[i][m] = '#';
        else
            s[i][1] = '#';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << s[i][j];
        cout << "\n";
    }
    return 0;
}