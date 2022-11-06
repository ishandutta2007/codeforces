#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int ans1 = n - 1 + n * (m - 1);
        int ans2 = m - 1 + m * (n - 1);
        if (ans1 > ans2)
            swap(ans1, ans2);
        cout << (k >= ans1 && k <= ans2 ? "YES" : "NO") << "\n";
    }
    return 0;
}