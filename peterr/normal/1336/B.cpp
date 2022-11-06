#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int arr[3][MAXN];
int sz[3];

long long solve(int a[MAXN], int b[MAXN], int c[MAXN], int n1, int n2, int n3)
{
    long long ans = 6E18;
    int p2 = 0;
    int p3 = 0;
    for (int i = 0; i < n1; i++)
    {
        while (p2 < n2 && b[p2] < a[i])
            p2++;
        if (p2 >= n2)
            break;
        while (p3 + 1 < n3 && c[p3 + 1] <= a[i])
            p3++;
        long long dx = a[i] - b[p2];
        long long dy = b[p2] - c[p3];
        long long dz = c[p3] - a[i];
        ans = min(ans, dx * dx + dy * dy + dz * dz);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
            cin >> sz[i];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < sz[i]; j++)
                cin >> arr[i][j];
        for (int i = 0; i < 3; i++)
            sort(arr[i], arr[i] + sz[i]);
        long long ans = 6E18;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                    continue;
                for (int k = 0; k < 3; k++)
                {
                    if (k == i || k == j)
                        continue;
                    ans = min(ans, solve(arr[i], arr[j], arr[k], sz[i], sz[j], sz[k]));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}