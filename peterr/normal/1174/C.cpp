#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> primes;
    int* arr = new int[n + 1];
    bool* isPrime = new bool[n+1];
    fill(isPrime, isPrime + n + 1, true);
    int count = 1;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            arr[i] = count++;
            for (int j = 2 * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
        else
        {
            for (int j = 0; j < primes.size(); j++)
            {
                if (i % primes[j] == 0)
                {
                    arr[i] = j + 1;
                    break;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++)
        cout << arr[i] << " ";
    return 0;
}