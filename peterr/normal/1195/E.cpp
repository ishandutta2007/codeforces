#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 3000;
int mat[MAXN][MAXN];
int minRow[MAXN][MAXN];
int n, m, a, b, g, x, y, z;


int main()
{
    cin >> n >> m >> a >> b >> g >> x >> y >> z;
    mat[0][0] = g;
    int prev = g;
    for (int i = 1; i < n * m; i++)
    {
        mat[i / m][i % m] = (int) ((ll) prev * x % z + y) % z;
        prev = mat[i / m][i % m];
    }
    for (int i = 0; i < n; i++)
    {
        deque<int> deq;
        for (int j = 0; j < b; j++)
        {
            int cur = mat[i][j];
            while (!deq.empty() && deq.back() >= cur)
            {
                deq.pop_back();
            }
            deq.push_back(cur);
        }
        for (int j = 0; j + b <= m; j++)
        {
            minRow[i][j] = deq.front();
            if (mat[i][j] == deq.front())
                deq.pop_front();
            if (j + b < m)
            {
                while (!deq.empty() && deq.back() >= mat[i][j + b])
                {
                    deq.pop_back();
                }
                deq.push_back(mat[i][j + b]);
            }
        }
    }
    long long ans = 0;
    for (int j = 0; j + b <= m; j++)
    {
        deque<int> deq;
        for (int i = 0; i < a; i++)
        {
            int cur = minRow[i][j];
            while (!deq.empty() && deq.back() >= cur)
            {
                deq.pop_back();
            }
            deq.push_back(cur);
        }
        for (int i = 0; i + a <= n; i++)
        {
            ans += deq.front();
            if (deq.front() == minRow[i][j])
                deq.pop_front();
            if (i + a < n)
            {
                while (!deq.empty() && deq.back() >= minRow[i + a][j])
                {
                    deq.pop_back();
                }
                deq.push_back(minRow[i + a][j]);
            }
        }
    }
    cout << ans;
    return 0;
}