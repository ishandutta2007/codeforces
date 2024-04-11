#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 3E5;
pair<int, int> arr[MAXN];
int fac[MAXN + 1];

int main()
{
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) (((long long) fac[i - 1] * i) % MOD);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    int ex = 0;
    bool sorted = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i].first > arr[i + 1].first)
            sorted = false;
        if (arr[i].second > arr[i + 1].second)
            sorted = false;
    }
    if (sorted)
    {
        ex = 1;
        int p1 = 0;
        while (p1 < n)
        {
            int p2 = p1;
            while (p2 + 1 < n && arr[p2 + 1].first == arr[p1].first && arr[p2 + 1].second == arr[p1].second)
                p2++;
            ex = (int) (((long long) ex * fac[p2 - p1 + 1]) % MOD);
            p1 = p2 + 1;
        }
    }
    int first = 1;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j + 1 < n && arr[j + 1].first == arr[i].first)
            j++;
        first = (int) (((long long) first * fac[j - i + 1]) % MOD);
        i = j;
    }
    sort(arr, arr + n, [] (pair<int, int> a, pair<int, int> b) {return a.second < b.second;});
    int second = 1;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j + 1 < n && arr[j + 1].second == arr[i].second)
            j++;
        second = (int) (((long long) second * fac[j - i + 1]) % MOD);
        i = j;
    }
    int bad = (first + second) % MOD;
    bad = (bad - ex + MOD) % MOD;
    int ans = (fac[n] - bad + MOD) % MOD;
    cout << ans << endl;
    return 0;
}