#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int a[MAXN];
int key[11];
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> primes;
    int cur = 2;
    while ((int) primes.size() < 11)
    {
        bool isPrime = true;
        for (int i = 2; i < cur; i++)
        {
            if (cur % i == 0)
                isPrime = false;
        }
        if (isPrime)
            primes.push_back(cur);
        cur++;
    }
    int t;
    cin >> t;
    while (t--)
    {
        fill(key, key + 11, 0);
        int n;
        cin >> n;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            for (int j = 0; j < 11; j++)
            {
                int p = primes[j];
                if (y % p == 0)
                {
                    if (key[j] == 0)
                    {
                        key[j] = ++m;
                    }
                    ans[i] = key[j];
                    break;
                }
            }
        }
        cout << m << "\n";
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}