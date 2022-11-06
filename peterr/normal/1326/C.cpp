#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MOD = 998244353;
int p[MAXN];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    int ans2 = 1;
    int ptr = 0;
    while (ptr < n && p[ptr] < n - k + 1)
    {
        ptr++;
    }
    for (int i = 0; i < k - 1; i++)
    {
        int j = ptr;
        ptr++;
        while (ptr < n && p[ptr] < n - k + 1)
            ptr++;
        int len = ptr - j;
        ans2 = (int) (((long long) ans2 * len) % MOD);
    }
    long long ans1 = 0;
    for (int i = 0; i < k; i++)
    {
        ans1 += n - i;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}