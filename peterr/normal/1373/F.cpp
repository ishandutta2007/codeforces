#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
const int PASS = 0;
const int FAIL = 1;
const int GOOD = 2;
int a[MAXN];
int b[MAXN];

int check(int left, int n)
{
    vector<int> cities(n);
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
        cities[i] = a[i];
        stations[i] = b[i];
    }
    cities[0] -= left;
    stations[0] -= left;
    int p = 1;
    while (p < n)
    {
        int amt = min(cities[p], stations[p - 1]);
        cities[p] -= amt;
        stations[p - 1] -= amt;
        amt = min(cities[p], stations[p]);
        cities[p] -= amt;
        stations[p] -= amt;
        if (cities[p])
            return FAIL;
        p++;
    }
    cities[0] -= stations[n - 1] + stations[0];
    if (cities[0] <= 0)
        return GOOD;
    return PASS;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        if (check(0, n) == FAIL)
        {
            cout << "NO\n";
            continue;
        }
        int left = 0;
        for (int jump = 1E9; jump; jump >>= 1)
        {
            while (left + jump <= b[0] && check(left + jump, n) != FAIL)
                left += jump;
        }
        if (check(left, n) == GOOD)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}