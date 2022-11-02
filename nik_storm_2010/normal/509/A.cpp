#include <iostream>

using namespace std;
const int N = 1e2;

long long a[N][N];

int main() {
    int n{};
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[1][i] = a[i][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            a[i][j] = a[i - 1][j] + a[i][j - 1];
    cout << a[n][n] << "\n";
    return 0;
}