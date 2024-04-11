#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E12;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        bool ans = false;
        for (int i = 1; i <= 10000; i++)
        {
            int j = 1;
            for (int jump = 10000; jump; jump >>= 1)
            {
                int jj = j + jump;
                while (j + jump <= 10000 && (long long) i * i * i + (long long) jj * jj * jj <= n)
                {
                    j += jump;
                    jj += jump;
                }
            }
            if ((long long) i * i * i + (long long) j * j * j == n)
            {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}