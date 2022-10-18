#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>

#define sz(a) (int)((a).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200001;

int cnt[N];
int arr[N];
int sz[N];
int ql[N], qr[N];

void inc(int n, int d)
{
 //   if (cnt[n] >= 0)
        sz[cnt[n]]--;
    cnt[n] += d;
   // if (cnt[n] >= 0)
        sz[cnt[n]]++;
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    int m;
    cin >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int timer = -1;
    int query = 0;
    vector<pair<pair<int, int>, pair<int, int> > > q;
    vector<pair<int, int> > change;
    set<int> setik;
    for (int i : a)
        setik.insert(i);
    int B = 47 * 47;
    for (int i = 0; i < m; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
          //  r--;
            ql[query] = l;
            qr[query] = r;
            q.push_back({{l / B, r / B}, {timer, query}});
            query++;
        }
        else
        {
            timer++;
            int p, x;
            cin >> p >> x;
            setik.insert(x);
            p--;
            change.push_back({p, x});
        }
    }
    map<int, int> mapa;
    int num = 0;
    for (int i : setik)
    {
        mapa[i] = num++;
    }
    for (int i = 0; i < n; i++)
        a[i] = mapa[a[i]];
    for (int i = 0; i <= timer; i++)
        change[i].second = mapa[change[i].second];
    sort(q.begin(), q.end());
    vector<int> ans(query, 0);
    timer = 1e9;
    int curl, curr;
    for (int i = 0; i < q.size(); i++)
    {
        int ind = q[i].second.second;
        int t = q[i].second.first;
        int l = ql[ind];
        int r = qr[ind];
        if (t < timer)
        {
            for (int i = 0; i < N; i++)
                cnt[i] = 0;
            for (int i = 0; i < n; i++)
                arr[i] = a[i];
            for (int i = 0; i < N; i++)
                sz[i] = 0;
            timer = -1;
            curl = l;
            curr = l;
        }
        while (curl > l)
        {
            curl--;
            inc(arr[curl], 1);
        }
        while (curr < r)
        {
            inc(arr[curr], 1);
            curr++;
        }
        while (curl < l)
        {
            inc(arr[curl], -1);
            curl++;
        }
        while (curr > r)
        {
            curr--;
            inc(arr[curr], -1);
        }
        while (timer < t)
        {
            timer++;
            int pos = change[timer].first;
            if (l <= pos && pos < r)
            {
                inc(arr[pos], -1);
                inc(change[timer].second, 1);
            }
            arr[pos] = change[timer].second;
        }
        int j = 0;
        while (sz[j])
            j++;
        ans[ind] = j;
    }
    for (int i : ans)
        cout << i << '\n';
    cout << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #elif KEK
        freopen("cnt-mex.in", "r", stdin);
        freopen("cnt-mex.out", "w", stdout);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}