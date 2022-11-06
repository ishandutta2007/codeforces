#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1E5 + 5;
int tenpow[MAXN];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main()
{
    tenpow[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        tenpow[i] = (int) ((long long) tenpow[i - 1] * 10 % MOD);
    }
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int n = (int) s.length();
    int mult = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            add(mult, (int) ((long long) tenpow[i - 1] * i % MOD));
        }
        int key = s[i] - '0';
        add(ans, (int) ((long long) mult * key % MOD));
        int numBefore = n - i - 1;
        if (numBefore)
        {
            int prs = (int) ((long long) numBefore * (numBefore + 1) / 2 % MOD);
            int temp = (int) ((long long) key * tenpow[i] % MOD);
            add(ans, (int) ((long long) temp * prs % MOD));
        }
    }
    cout << ans << "\n";
    return 0;
}