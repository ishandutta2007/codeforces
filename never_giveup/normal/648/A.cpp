#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e2;

ll n, m, q[maxn][maxn];

ll a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        char c;
        cin >> c;
        if (c == '.')
            q[i][j] = 0;
        else
            q[i][j] = 1;
    }
    for (int i = 0; i < m; i++){
        int sum = 0;
        for (int j = n - 1; j >= 0 && q[j][i] == 1; j--)
            sum++;
        a[i] = sum;
    }
    ll x = 0, y = 0;
    for (int i = 0; i < m - 1; i++)
        x = max(x, a[i] - a[i + 1]), y = max(y, a[i + 1] - a[i]);
    cout << y << ' ' << x;
}