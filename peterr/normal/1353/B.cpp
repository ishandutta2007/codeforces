#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
int a[MAXN];
int b[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        vector<int> v1;
        vector<int> v2;
        for (int i = 0; i < n; i++)
        {
            v1.push_back(a[i]);
            v2.push_back(b[i]);
        }
        reverse(v1.begin(), v1.end());
        long long ans = 0;
        while (k && v2.back() > v1.back())
        {
            v1.pop_back();
            ans += v2.back();
            v2.pop_back();
            k--;
        }
        while (!v1.empty())
        {
            ans += v1.back();
            v1.pop_back();
        }
        cout << ans << endl;
    }
    return 0;
}