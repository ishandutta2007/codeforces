#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXM = MAXN * (MAXN - 1) / 2;
vector<int> primes;
bool isPrime[MAXM + 1];

int main()
{
    int gap = 0;
    fill(isPrime + 2, isPrime + MAXM + 1, true);
    for (int i = 2; i <= MAXM; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAXM; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    int edges = n;
    int countt = 0;
    vector<pair<int, int>> ans;
    while (!isPrime[edges])
    {
        ans.push_back({1 + countt, n / 2 + 1 + countt});
        edges++;
        countt++;
    }
    cout << edges << endl;
    for (int i = 1; i < n; i++)
        cout << i << " " << i + 1 << endl;
    cout << n << " " << 1 << endl;
    for (pair<int, int> p : ans)
        cout << p.first << " " << p.second << endl;


    return 0;
}