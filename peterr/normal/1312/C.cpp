#include <bits/stdc++.h>

using namespace std;

const int LOG = 80;
const int MAXN = 30;
const long long MAXA = 1E16;
long long a[MAXN];
bool used[LOG];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<long long> v;
        long long x = 1;
        int m = 0;
        while (x <= MAXA)
        {
            v.push_back(x);
            x *= k;
            used[m++] = false;
        }
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            long long y = a[i];
            for (int j = m - 1; j >= 0; j--)
            {
                if (!used[j] && v[j] <= y)
                {
                    used[j] = true;
                    y -= v[j];
                }
            }
            if (y > 0)
                ans = false;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}