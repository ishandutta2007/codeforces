#include<iostream>
using namespace std;

typedef unsigned long long LL;
const int N = 2000 + 10;
const int M = 200 + 10;
const LL T = 29;

string s1[N], s2[M];
int n, m;

LL pw26[M];
LL f[N], g[M][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s1[i];
    for(int i = 0; i < m; i++) cin >> s2[i];

    pw26[0] = 1;
    for(int i = 1; i <= m; i++) pw26[i] = pw26[i - 1] * T;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) f[i] = f[i] * LL(T) + (s1[i][j] - 'a');

    //for(int i = 0; i < n; i++) cout << f[i] << endl;

    for(int i = 0; i < m; i++) {
        //for(int j = 0; j < m; j++) g[i][0] = g[i][0] * LL(T) + (s2[i][j] - 'a');
        /*for(int j = m; j < n; j++) {
            g[i][j - m + 1] = g[i][j - m] - pw26[m] * (s2[i][j - m] - 'a');
            g[i][j - m + 1] = g[i][j - m + 1] * T + (s2[i][j] - 'a');
        }*/
        for(int j = 0; j <= n - m; j++)
            for(int k = 0; k < m; k++) g[i][j] = g[i][j] * LL(T) + (s2[i][j + k] - 'a');
    }

    /*for(int i = 0; i < m; i++) {
        for (int j = 0; j <= n - m; j++) cout << g[i][j] << ' ';
        cout << endl;
    }*/

    for(int i = 0; i <= n - m; i++)
        for(int j = 0; j <= n - m; j++) {
            bool ok = true;
            for(int k = 0; k < m; k++)
                if(f[i + k] != g[k][j]) { ok = false; break; }
            if(ok) { cout << i + 1 << ' ' << j + 1 << '\n'; return 0; }
        }

    cout << -1 << '\n';
    return 0;
}