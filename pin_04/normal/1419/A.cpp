#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> c;
            if (i & 1)
            {
                if ((c - '0') & 1) odd1 = true;
                else even1 = true;
            } else {
                if ((c - '0') & 1) odd2 = true;
                else even2 = true;
            }
        }
        if (n & 1)
        {
            if (odd1) cout << "1\n";
            else cout << "2\n";
        } else {
            if (even2) cout << "2\n";
            else cout << "1\n";
        }
    }
    return 0;
}