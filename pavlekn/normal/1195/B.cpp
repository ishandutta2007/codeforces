#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < MAXN; ++i)
    {
        int cur = i * (i + 1) / 2;
        if (cur - (n - i) == k)
        {
            cout << n - i << endl;
            return 0;
        }
    }
}