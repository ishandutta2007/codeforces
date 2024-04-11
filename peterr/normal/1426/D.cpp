#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    set<long long> s;
    s.insert(0);
    long long pre = 0;
    for (int i = 0; i < n; i++)
    {
        pre += a[i];
        if (s.count(pre))
        {
            ans++;
            s.clear();
            s.insert(0);
            pre = a[i];
            s.insert(pre);
        }
        s.insert(pre);
    }
    cout << ans << "\n";
    return 0;
}