#include <bits/stdc++.h>

using namespace std;

const long long MAXX = 2E12;
const int MAXN = 2E5;
long long a[MAXN];
int b[MAXN];
vector<tuple<long long, long long, int>> v[MAXN];

bool check(long long x, int n, int k)
{
    for (int i = 0; i < k; i++)
        v[i].clear();
    for (int i = 0; i < n; i++)
    {
        long long cycles = a[i] / b[i];
        if (cycles < k)
            v[cycles].push_back(make_tuple(a[i] / b[i], a[i], i));
    }
    int p = 0;
    for (int i = 0; i < k; i++)
    {
        while (p < k && v[p].empty())
            p++;
        if (p >= k)
            break;
        tuple<long long, long long, int> t = v[p].back();
        v[p].pop_back();
        int ind = get<2>(t);
        if (get<0>(t) < i)
            return false;
        get<1>(t) += x;
        get<0>(t) = (get<1>(t)) / b[ind];
        if (i < k - 1 && get<0>(t) <= i)
            return false;
        if (get<0>(t) < k)
            v[get<0>(t)].push_back(t);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    if (!check(MAXX, n, k))
        cout << -1 << "\n";
    else
    {
        long long ans = -1;
        for (long long jump = MAXX >> 1; jump > 0; jump >>= 1)
        {
            while (ans + jump <= MAXX && !check(ans + jump, n, k))
                ans += jump;
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}