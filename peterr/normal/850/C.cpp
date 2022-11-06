#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int MAXP = 1E5;
int a[MAXN];
map<int, int> m;
bool isComp[MAXP];
vector<int> primes;

int getGrundy(int mask)
{
    //cout << mask << endl;
    if (mask == 0)
        return 0;
    if (m.count(mask))
        return m[mask];
    vector<int> vec;
    for (int i = 0; (1 << i) <= mask; i++)
    {
        int newMask = mask & ((1 << i) - 1);
        newMask |= (~((1 << i) - 1) & mask) >> (i + 1);
        vec.push_back(getGrundy(newMask));
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    int p = 0;
    while (p < (int) vec.size())
    {
        if (vec[p] == ans)
            ans++;
        p++;
    }
    m[mask] = ans;
    return ans;
}

int main()
{
    for (int i = 2; i < MAXP; i++)
    {
        if (!isComp[i])
            primes.push_back(i);
        for (int j = 0; j < (int) primes.size() && primes[j] * i < MAXP; j++)
        {
            isComp[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (int p : primes)
    {
        int mask = 0;
        for (int j = 0; j < n; j++)
        {
            int cur = 0;
            while (a[j] % p == 0)
            {
                a[j] /= p;
                cur++;
            }
            if (cur)
                mask |= (1 << (cur - 1));
        }
        sum ^= getGrundy(mask);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == a[i])
                    a[j] = 1;
            }
            sum ^= 1;
        }
    }
    if (sum == 0)
        cout << "Arpa\n";
    else
        cout << "Mojtaba\n";
    return 0;
}