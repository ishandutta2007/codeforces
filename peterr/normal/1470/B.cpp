#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1000000;
const int MAXN = 3E5;
vector<int> primes;
int isComp[MAXA + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= MAXA; i++)
    {
        if (isComp[i])
            continue;
        isComp[i] = i;
        primes.push_back(i);
        if ((long long) i * i > MAXA)
            continue;
        for (int j = i * 2; j <= MAXA; j += i)
        {
            isComp[j] = i;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            for (int p : primes)
            {
                if (p * p > x)
                    break;
                while (x % (p * p) == 0)
                    x /= p * p;
            }
            mp[x]++;
        }
            /*
        for (auto it : mp)
            cout << "map " << it.first << " " << it.second << endl;
        */
        int ans1 = 0;
        for (auto it : mp)
            ans1 = max(ans1, it.second);
        int sum = 0;
        int ans2 = 0;
        if (mp.count(1))
            sum += mp[1];
        for (auto it : mp)
        {
            if (it.first != 1 && !(it.second & 1))
                sum += it.second;
            if (it.first != 1 && (it.second & 1))
                ans2 = max(ans2, it.second);
        }
        ans2 = max(ans2, sum);
        int q;
        cin >> q;
        while (q--)
        {
            long long w;
            cin >> w;
            if (w)
            {
                cout << ans2 << "\n";
            }
            else
            {
                cout << ans1 << "\n";
            }
        }
    }
    return 0;
}