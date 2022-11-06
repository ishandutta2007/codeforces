#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
int a[MAXN];
int b[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int x = 0;
    int y = 0;
    while (a[x] % p == 0)
        x++;
    while (b[y] % p == 0)
        y++;
    if (x > y)
        swap(x, y);
    cout << x + y << endl;
    return 0;
}