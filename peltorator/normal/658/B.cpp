#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> t(n);
    vector<int> cur(k, -1);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int ui = 0; ui < q; ui++)
    {
        int tau, num;
        cin >> tau >> num;
        num--;
        if (tau == 1)
        {
            int v = -1, p = 1e9;
            for (int i = 0; i < k; i++)
            {
                if (cur[i] == -1)
                {
                    v = i;
                    p = -1;
                }
                else if (t[cur[i]] < p)
                {
                    p = t[cur[i]];
                    v = i;
                }
            }
            if (p < t[num])
                cur[v] = num;
        }
        else
        {
            bool ok = false;
            for (int i = 0; i < k; i++)
                if (cur[i] == num)
                    ok = true;
            if (ok)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}