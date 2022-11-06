#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
bool visited[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fill(visited, visited + n, false);
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x += i;
            x %= n;
            if (x < 0)
                x += n;
            if (visited[x])
                ans = false;
            visited[x] = true;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}