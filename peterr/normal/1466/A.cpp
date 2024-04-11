#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int a[MAXN];

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
        set<int> seen;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                    continue;
                seen.insert(abs(a[i] - a[j]));
            }
        }
        cout << seen.size() << "\n";
    }
    return 0;
}