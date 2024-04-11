#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
tuple<int, int, int> a[MAXN + 1];
tuple<int, int, int> b[MAXN + 1];
int ans[MAXN + 1];

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
        for (int i = 1; i <= n; i++)
        {
            cin >> get<0>(a[i]) >> get<1>(a[i]);
            get<2>(a[i]) = i;
            b[i] = a[i];
            swap(get<0>(b[i]), get<1>(b[i]));
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        fill(ans + 1, ans + n + 1, -1);
        int ptr = 1;
        int ptr2 = 1;
        int mn = 1E9 + 7;
        int where = -1;
        int h = -1;
        while (ptr <= n)
        {
            h = get<0>(a[ptr]);
            while (ptr2 <= n && get<0>(b[ptr2]) <= h)
            {
                if (mn < get<1>(b[ptr2]))
                {
                    ans[get<2>(b[ptr2])] = where;
                }
                ptr2++;
            }
            int newMin = mn;
            int newWhere = -2;
            while (ptr <= n && get<0>(a[ptr]) == h)
            {
                if (mn < get<1>(a[ptr]))
                {
                    ans[get<2>(a[ptr])] = where;
                }
                if (get<1>(a[ptr]) < newMin)
                {
                    newWhere = get<2>(a[ptr]);
                    newMin = min(mn, get<1>(a[ptr]));
                }
                ptr++;
            }
            if (newMin < mn)
            {
                where = newWhere;
                mn = min(mn, newMin);
            }
        }
        while (ptr2 <= n)
        {
            if (mn < get<1>(b[ptr2]))
            {
                ans[get<2>(b[ptr2])] = where;
            }
            ptr2++;
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}