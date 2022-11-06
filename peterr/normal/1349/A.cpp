#include <bits/stdc++.h>

using namespace std;

const int MAXA = 2E5;
const int MAXN = 1E5;
const int MAXP = 1E3;
bool isComp[MAXP + 1];
vector<int> primes;
int a[MAXN];
int freq[MAXA + 1];

int getNum(int p, int ind)
{
    int ans = 0;
    while (a[ind] % p == 0)
    {
        ans++;
        a[ind] /= p;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= MAXP; i++)
    {
        if (!isComp[i])
            primes.push_back(i);
        for (int j = 0; j < (int) primes.size() && i * primes[j] <= MAXP; j++)
        {
            isComp[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 1;
    for (int p : primes)
    {
        int min1 = getNum(p, 0);
        int min2 = getNum(p, 1);
        if (min2 < min1)
            swap(min1, min2);
        for (int i = 2; i < n; i++)
        {
            int x = getNum(p, i);
            if (x < min2)
                min2 = x;
            if (min2 < min1)
                swap(min1, min2);
        }
        while (min2)
        {
            min2--;
            ans *= p;
        }
    }
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    for (int i = 2; i <= MAXA; i++)
    {
        if (freq[i] >= n - 1)
            ans *= i;
    }
    cout << ans << endl;
    return 0;
}