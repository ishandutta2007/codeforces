#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN];
bool locked[MAXN];

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
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> locked[i];
            if (!locked[i])
                v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            if (!locked[i])
            {
                a[i] = v.back();
                v.pop_back();
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}