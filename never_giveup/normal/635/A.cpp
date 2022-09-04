#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e6;

int q[100][100];

int main()
{
    ll r, c, n, k;
    cin >> r >> c >> n >> k;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        q[a - 1][b - 1] = 1;
    }
    int ans = 0;
    for (int i1 = 0; i1 < r; i1++)
        for (int j1 = 0; j1 < c; j1++)
            for (int i2 = i1; i2 < r; i2++)
                for (int j2 = j1; j2 < c; j2++){
                    int sum = 0;
                    for (int i = i1; i <= i2; i++)
                        for (int j = j1; j <= j2; j++)
                            sum += q[i][j];
                    if (sum >= k)
                        ans++;
                }
    cout << ans;
}