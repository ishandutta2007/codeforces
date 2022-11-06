#include <bits/stdc++.h>

using namespace std;

const int MAXB = 2750131;
int freq[MAXB+1];
vector<int> primes;
vector<int> ans;

int div(int x)
{
    for (int i = 2; i <= x; i++)
    {
        if (x % i == 0)
            return x / i;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool* isPrime = new bool[2750132];
    fill(isPrime, isPrime + 2750132, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAXB; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= MAXB; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        int a;
        cin >> a;
        freq[a]++;
    }

    for (int i = MAXB; i >= 2; i--)
    {
        if (freq[i] > 0 && !isPrime[i])
        {
            for (int j = 0; j < freq[i]; j++)
                ans.push_back(i);
            freq[div(i)] -= freq[i];
        }
    }

    for (int i = 2; i <= MAXB; i++)
    {
        if (freq[i] > 0 && isPrime[i])
        {
            for (int j = 0; j < freq[i]; j++)
                ans.push_back(i);
            freq[primes[i-1]] -= freq[i];
        }
    }

    for (int num : ans)
        cout << num << " ";
    return 0;
}