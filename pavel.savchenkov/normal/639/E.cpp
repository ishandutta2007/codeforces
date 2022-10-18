#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

struct prob
{
    int p;
    int t;
    int id;

    bool operator < (const prob &other) const
    {
        return (ll)p * other.t > (ll)other.p * t;
    }

    bool same (const prob &other) const
    {
        return (ll)p * other.t == (ll)other.p * t;
    }

    void print () const
    {
        fprintf(stderr, "%d/%d\n", p, t);
    }
};

bool cmp (const prob &left, const prob &right)
{
    return left.p < right.p;
}

typedef double T;

void solve (int n)
{
    vector<prob> v(n);
    ll sumt = 0;
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i].p);
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i].t), sumt += v[i].t;
    for (int i = 0; i < n; i++)
        v[i].id = i;

    sort(ALL(v));
    vector<vector<prob>> groups;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || !v[i].same(v[i - 1]))
            groups.pb({v[i]});
        else
            groups.back().pb(v[i]);
    }

    vector<ll> time_group(sz(groups));
    for (int i = 0; i < sz(groups); i++)
    for (const auto &pt : groups[i])
        time_group[i] += pt.t;

    vector<ll> mint(n), maxt(n);
    ll tme = 0;
    for (int i = 0; i < sz(groups); i++)
    {
        for (const auto &pt : groups[i])
            mint[pt.id] = tme + pt.t;
        tme += time_group[i];
        for (const auto &pt : groups[i])
            maxt[pt.id] = tme;
    }

    vector<prob> order = v;
    sort(ALL(order), cmp);

    auto check = [&] (T c) -> bool
    {
        T maxpref = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j < n && order[j].p < order[i].p)
            {
                T cost = (T)order[j].p * (1.0 - (T)mint[order[j].id] / sumt * c);
                maxpref = max(maxpref, cost);
                j++;
            }

            T cost = (T)order[i].p * (1.0 - (T)maxt[order[i].id] / sumt * c);
            if (cost < maxpref)
                return false;
        }

        return true;
    };

    T left = 0, right = 1;
    for (int it = 0; it < 50; it++)
    {
        T mid = (left + right) / 2;
        if (check(mid))
            left = mid;
        else
            right = mid;
    }

    left = (left + right) / 2;
    printf("%.20f\n", (double)left);
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