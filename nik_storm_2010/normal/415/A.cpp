#include <iostream>

using namespace std;

int ans[200];

int main()
{
    ios_base::sync_with_stdio(true);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        for (int j = x; j <= n; j++) if (ans[j] == 0) ans[j] = x;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}