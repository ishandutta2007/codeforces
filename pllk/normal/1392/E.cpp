#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll r[55][55];
ll w[55][55];

void dfs(int y, int x, ll k) {
    if (y == n && x == n) {
        cout << y << " " << x << endl;
        return;
    }
    if (y > n || x > n) return;
    if ((k&w[y][x]) && !r[y][x]) return;
    if (!(k&w[y][x]) && r[y][x]) return;
    cout << y << " " << x << endl;
    dfs(y+1,x,k);
    dfs(y,x+1,k);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll b = 1LL<<(i+j-2);
            w[i][j] = b;
            r[i][j] = (i%2 == 0) ? b : 0;
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll k;
        cin >> k;
        dfs(1,1,k);
    }
}