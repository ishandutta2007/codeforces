#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, int> piii;
const int N = 1e5 + 10;

pair <pii, int> a[N];
pair <pii, pii> b[N];
int res[N];
set <piii> base;

int main()
{
    ios_base::sync_with_stdio(false);
    int n{};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    int m{};
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i].first.first >> b[i].first.second >> b[i].second.first;
        b[i].second.second = i;
    }
    sort(b + 1, b + m + 1);
    int i{1}, j{1};
    while (i <= n)
        if (j > m || a[i].first.first < b[j].first.first)
        {
            while (!base.empty() && (*base.begin()).first.first < a[i].first.first)
                base.erase(base.begin());
            set <piii>::iterator it{base.lower_bound({{a[i].first.second, 0}, 0})};
            if (it == base.end())
            {
                cout << "NO\n";
                return 0;
            }
            piii current{*it};
            res[a[i].second] = current.second;
            current.first.second--;
            base.erase(it);
            if (current.first.second)
                base.insert(current);
            i++;
        }
        else
        {
            base.insert({{b[j].first.second, b[j].second.first}, b[j].second.second});
            j++;
        }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
    return 0;
}