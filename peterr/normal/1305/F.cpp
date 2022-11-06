#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MAXP = 1E6;
vector<int> primes;
int isComp[MAXP + 1];
long long a[MAXN];

void addDiv(set<long long> &s, long long x)
{
    if (x <= 1)
        return;
    if (x > MAXP)
    {
        for (int p : primes)
        {
            if ((long long) p * p > x)
                break;
            if (x % p == 0)
            {
                while (x % p == 0)
                {
                    x /= p;
                }
                s.insert(p);
            }
        }
    }
    if (x <= MAXP)
    {
        while (x > 1)
        {
            int p = isComp[x];
            while (x % p == 0)
                x /= p;
            s.insert(p);
        }
    }
    if (x > 1)
        s.insert(x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= MAXP; i++)
    {
        if (!isComp[i])
        {
            primes.push_back(i);
            isComp[i] = i;
        }
        for (int j = 0; j < (int) primes.size() && primes[j] * i <= MAXP; j++)
        {
            isComp[i * primes[j]] = primes[j];
            if (i % primes[j] == 0)
                break;
        }
    }
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
            ans++;
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(a, a + n, rng);
    set<long long> nums;
    for (int i = 0; i < 30; i++)
    {
        addDiv(nums, a[i]);
        addDiv(nums, a[i] + 1);
        addDiv(nums, a[i] - 1);
    }
    for (long long x : nums)
    {
        long long cost = 0;
        for (int i = 0; i < n && cost < ans; i++)
        {
            if (a[i] < x)
                cost += x - a[i];
            else
            {
                long long mod = a[i] % x;
                cost += min(mod, x - mod);
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}