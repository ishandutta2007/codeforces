#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

void solve (int n)
{
    int d, h;
    cin >> d >> h;

    if (d == 1)
    {
        if (n == 2 && h == 1)
        {
            printf("1 2\n");
            return;
        }
        else
        {
            puts("-1");
            return;
        }
    }
    if (2 * h < d)
    {
        puts("-1");
        return;
    }

    vi path1, path2;
    path1.pb(1);
    path2.pb(1);

    int curv = 2;
    for (int j = 0; j < h; j++)
        path1.pb(curv), curv++;
    for (int j = 0; j < d - h; j++)
        path2.pb(curv), curv++;

    vector<pair<int, int>> e;
    assert(sz(path1) >= 2);
    while (curv != n + 1)
        e.pb(mp(path1[sz(path1) - 2], curv)), curv++;

    for (int j = 1; j < sz(path1); j++)
        e.pb(mp(path1[j - 1], path1[j]));
    for (int j = 1; j < sz(path2); j++)
        e.pb(mp(path2[j - 1], path2[j]));

    assert(sz(e) == n - 1);
    for (int i = 0; i < sz(e); i++)
        printf("%d %d\n", e[i].first, e[i].second);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif

  //  ios_base::sync_with_stdio(false);
  //  cin.tie(0);

    int n;
    while (cin >> n)
        solve (n);
}