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
    int k, a, b, c, d;
    cin >> k >> a >> b >> c >> d;

    if (k <= n || n == 4)
    {
        puts("-1");
        return;
    }
    else
    {
        set<int> all;
        for (int i = 1; i <= n; i++)
            all.insert(i);

        vi ans(n);

        auto add = [&] (int id, int pos) -> void
        {
            assert(all.count(id));
            all.erase(id);
            ans[pos] = id;
        };

        add(a, 0);
        add(c, 1);
        add(d, n - 2);
        add(b, n - 1);
        int pos = 2;
        while (!all.empty())
            add(*all.begin(), pos++);
        assert(pos == n - 2);

        for (int i = 0; i < n; i++)
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
        swap(ans[0], ans[1]);
        swap(ans[n - 2], ans[n - 1]);
        for (int i = 0; i < n; i++)
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
        solve(n);
}