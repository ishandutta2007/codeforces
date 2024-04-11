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
        long long n;
        cin >> n;
        vector<pair<long long, int>> primes;
        long long temp = n;
        for (int i = 2; (long long) i * i <= temp; i++)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            if (cnt)
                primes.push_back(make_pair(i, cnt));
        }
        if (n > 1)
            primes.push_back(make_pair(n, 1));
        vector<long long> ans;
        while (!primes.empty())
        {
            long long nxt = 1;
            int len = (int) primes.size();
            for (int i = len - 1; i >= 0; i--)
            {
                nxt *= primes[i].first;
                primes[i].second--;
                if (primes[i].second == 0)
                {
                    swap(primes[i], primes.back());
                    primes.pop_back();
                }
            }
            ans.push_back(nxt);
        }
        reverse(ans.begin(), ans.end());
        cout << (int) ans.size() << "\n";
        for (long long x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}