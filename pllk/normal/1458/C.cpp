#include <iostream>

using namespace std;

int a[1111][1111];
int b[1111][1111];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        string s;
        cin >> s;
        int d[3] = {0};
        int p[3] = {0,1,2};
        for (int i = 0; i < m; i++) {
            if (s[i] == 'L') d[p[1]]--;
            if (s[i] == 'R') d[p[1]]++;
            if (s[i] == 'D') d[p[0]]++;
            if (s[i] == 'U') d[p[0]]--;
            if (s[i] == 'I') swap(p[1],p[2]);
            if (s[i] == 'C') swap(p[0],p[2]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int f[3] = {i-1,j-1,a[i][j]-1};
                for (int k = 0; k < 3; k++) {
                    f[k] = ((f[k]+d[k])%n+n)%n;
                }
                b[f[p[0]]+1][f[p[1]]+1] = f[p[2]]+1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}