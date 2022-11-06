#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int coffee[MAXN];
int n, m;

bool check(int days)
{
    long long pages = 0;
    int index = n - 1;
    int countt = 0;
    while (index >= 0)
    {
        for (int i = 0; index >= 0 && i < days; i++)
        {
            pages += max(0, coffee[index] - countt);
            index--;
        }
        countt++;
    }
    return pages >= m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> coffee[i];
    sort(coffee, coffee + n);
    if (!check(n))
    {
        cout << "-1" << endl;
    }
    else
    {
        int ans = 0;
        for (int jump = n / 2 + 1; jump > 0; jump /= 2)
        {
            while (!check(ans + jump))
            {
                ans += jump;
            }
        }
        cout << ans + 1 << endl;
    }

    return 0;
}