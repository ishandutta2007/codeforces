#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int planks[MAXN];

bool check(int n, int k)
{
    if (n < k + 2)
        return false;
    /*
    long long a = 0, b = 0;
    for (int i = n - 1; i >= k; i--)
    {
        if (a <= b)
        {
            a += planks[i];
        }
        else
        {
            b += planks[i];
        }
    }
    */
    return planks[n - 2] >= k + 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> planks[i];
        }
        sort(planks, planks + n);
        int ans = 0;
        for (int jump = n / 2 + 1; jump > 0; jump /= 2)
        {
            while (check(n, ans + jump))
                ans += jump;
        }
        cout << ans << endl;
    }
    return 0;
}