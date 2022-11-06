#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> a;
vector<int> b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        a.clear();
        b.clear();
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (!x)
                a.push_back(abs(y));
            else
                b.push_back(abs(x));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += sqrt((long long) a[i] * a[i] + (long long) b[i] * b[i]);
        }
        cout << fixed << setprecision(10) << ans << "\n";
    }
    return 0;
}