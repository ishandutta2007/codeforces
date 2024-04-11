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
        if (n % k == 0)
        {
            cout << "1\n";
            continue;
        }
        int num = n / k;
        long long biggest = ((long long) k * (num + 1) + (n - 1)) / n;
        cout << biggest << "\n";
    }
    return 0;
}