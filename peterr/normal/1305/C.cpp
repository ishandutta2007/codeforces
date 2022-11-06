#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MAXM = 1000;
int freq[MAXM];
int a[MAXN];

int modpow(int b, int e, int m)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % m);
        b = (int) ((long long) b * b % m);
        e >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ans = 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int mod = x % m;
        for (int j = 0; j < m; j++)
        {
            if (freq[j] == 0)
                continue;
            int dist = (mod - j + m) % m;
            //cout << dist << endl;
            ans = (int) ((long long) ans * modpow(dist, freq[j], m) % m);
        }
        freq[mod]++;
        if (freq[mod] > 1)
        {
            ans = 0;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}