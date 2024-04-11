#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
const int MOD = 998244353;
int freq[MAXN + 1];
vector<int> child[MAXN];

int modInv(int x)
{
    int ans = 1;
    int k = MOD - 2;
    while (k > 0)
    {
        if (k & 1)
        {
            ans = (int) (((long long) ans * x) % MOD);
        }
        x = (int) (((long long) x * x) % MOD);
        k = k / 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            child[i].push_back(x);
            freq[x]++;
        }
    }
    int ans = 0;
    int nInv = modInv(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int) child[i].size(); j++)
        {
            int item = child[i][j];
            int p = (int) (((long long) nInv * modInv((int) child[i].size())) % MOD);
            int q = (int) (((long long) freq[item] * nInv) % MOD);
            int t = (int) (((long long) p * q) % MOD);
            ans = (ans + t) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}