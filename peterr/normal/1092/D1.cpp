#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

bool solve(int n)
{
    int p = 0;
    vector<int> v;
    while (p < n)
    {
        while (p < n && (a[p] & 1) == 0)
            p++;
        int cnt = 0;
        while (p < n && (a[p] & 1) == 1)
        {
            p++;
            cnt++;
        }
        if (cnt & 1)
        {
            if (!v.empty() && (abs(p - v.back()) & 1) == 1)
                v.pop_back();
            else
                v.push_back(p);
        }
    }
    return v.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (solve(n))
        cout << "YES\n";
    else
    {
        for (int i = 0; i < n; i++)
            a[i]++;
        if (solve(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}