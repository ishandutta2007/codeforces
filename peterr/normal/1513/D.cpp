#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
pair<int, int> where[MAXN];
bool visited[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        fill(visited, visited + n, false);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            where[i] = {a[i], i};
        }
        sort(where, where + n);
        long long ans = 0;
        int edges = 0;
        for (int i = 0; i < n; i++)
        {
            int val = where[i].first;
            int ind = where[i].second;
            if (p <= val)
                break;
            if (visited[ind])
                continue;
            for (int j = ind - 1; j >= 0; j--)
            {
                if (a[j] % val != 0)
                    break;
                edges++;
                ans += val;
                if (visited[j])
                    break;
                visited[j] = true;
            }
            for (int j = ind + 1; j < n; j++)
            {
                if (a[j] % val != 0)
                    break;
                edges++;
                ans += val;
                if (visited[j])
                    break;
                visited[j] = true;
            }
            visited[ind] = true;
        }
        ans += (long long) (n - 1 - edges) * p;
        cout << ans << "\n";
    }
    return 0;
}