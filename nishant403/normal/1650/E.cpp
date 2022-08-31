#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9 + 7;

int mod_pow(int a, int b, int M = MOD)
{
    if (a == 0) return 0;
    b %= (M - 1);  //M must be prime here

    int res = 1;

    while (b > 0)
    {
        if (b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }

    return res;
}


void solve()
{
    int n, d;
    cin >> n >> d;

    int a[n];
    f(i, n) cin >> a[i];

    int last_gap = d - a[n - 1];

    multiset<int> ms;

    ms.insert(a[0] - 1);

    for (int i = 1;i < n;i++) {
        ms.insert(a[i] - a[i - 1] - 1);
    }

    int res = *ms.begin();

    f(i, n) {
        vi ins, del;

        //what if we remove ith one ? 
        int orig = a[i] - 1;
        if (i > 0) orig = a[i] - a[i - 1] - 1;

        ins.pb(orig);
        ms.erase(ms.find(orig));

        //the next one gets benefit from this
        if (i < n - 1) {
            int nex_rng = a[i + 1] - a[i] - 1;
            int new_rng = a[i + 1] - 1;
            if (i > 0) new_rng = a[i + 1] - a[i - 1] - 1;

            ms.erase(ms.find(nex_rng));
            ins.pb(nex_rng);
            ms.insert(new_rng);
            del.pb(new_rng);
        }

        int temp_gap = last_gap - 1;

        if (i == n - 1) {
            temp_gap = d - a[n - 2] - 1;
        }

        //Now here we find what can be the answer 
        int laster = *ms.rbegin();

        int best = max(temp_gap, (laster - 1) / 2);

        del.pb(best);
        ms.insert(best);

        res = max(res, *ms.begin());

        //now restore stuff
        for (auto x : ins) ms.insert(x);
        for (auto x : del) ms.erase(ms.find(x));
    }


    cout << res << '\n';


}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}