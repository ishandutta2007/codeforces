#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int num = n - k + 1;
        for (int i = 1; i <= k - num; i++)
            cout << i << " ";
        for (int i = k; i > k - num; i--)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}