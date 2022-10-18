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
#include <random>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const int B = 450;
const int N = 250005;

int bl[N];
int mx[N], cnt[N], d[N];
int arr[N];
int fir[N], last[N];
int tin[N], tout[N];

vector<int> g[N];

int timer = 1;

vector<int> eul;

void dfs(int v, int p)
{
    tin[v] = timer++;
    fir[v] = eul.size();
    eul.push_back(v);
    for (int u : g[v])
        if (u != p)
            dfs(u, v);
    last[v] = eul.size();
    tout[v] = timer++;
}

bool pr(int p, int v)
{
    return tin[p] <= tin[v] && tout[v] <= tout[p];
}

void upd(int l, int r, int val)
{
    int L = 0;
    while (L * B < l)
        L++;
    int R = 0;
    while (R * B < r)
        R++;
    R--;
    int LB = L * B, RB = R * B;
//    cout << "      " << ' ' << LB << ' ' << RB << endl;
 //   for (int i = 0; i < r; i++)
   //             cout << arr[i] << ' ' ;
     //       cout << endl;
    int T = l;
    if (L)
    {
        for (int i = 0; i < B; i++)
            arr[LB - B + i] += d[L - 1];
        d[L - 1] = 0;
        for (int i = l; i < min(LB, r); i++)
            arr[i] += val;
        T = min(LB, r);
        mx[L - 1] = -1e9;
        cnt[L - 1] = 0;
        for (int i = 0; i < B; i++)
        {
            int t = arr[LB - B + i];
            if (t > mx[L - 1])
            {
                mx[L - 1] = t;
                cnt[L - 1] = 1;
            }
            else if (t == mx[L - 1])
                cnt[L - 1]++;
        }
    }
   // if (R != L - 1)
    {
        for (int i = 0; i < B; i++)
        arr[RB + i] += d[R];
        d[R] = 0;
      //  if (!L)
        {
     //       for (int i = 0; i < r; i++)
       //         cout << arr[i] << ' ' ;
         //   cout << endl;
        }
        
      //  if (!L || LB <= r)
            for (int i = max(RB, T); i < r; i++)
                arr[i] += val;
      //  if (!L)
        {
        //    for (int i = 0; i < r; i++)
          //      cout << arr[i] << ' ' ;
            //cout << endl;
        }
        mx[R] = -1e9;
        cnt[R] = 0;
        for (int i = 0; i < B; i++)
        {
            int t = arr[RB + i];
            if (t > mx[R])
            {
                mx[R] = t;
                cnt[R] = 1;
            }
            else if (t == mx[R])
                cnt[R]++;
        }
    }
    for (int i = L; i < R; i++)
    {
        mx[i] += val;
        d[i] += val;
    }
}

bool cmp(int v, int u)
{
    return tin[v] < tin[u];
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    for (int i = 0; i < N; i++)
        mx[i] = -1000;
    for (int i = 0; i < N; i++)
        bl[i] = i / B;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    set<pair<int, int> > q;
    int k = 0;
    while (k * B < 2 * n + 5)
        k++;
    int kek = 0;
 //   arr[0] = -1;
    for (int i = n; i < N; i++)
        arr[i] = -1;
    for (int i = 0; (i + 1) * B < N; i++)
    {
        mx[i] = -5;
        int IB = i * B;
        for (int j = 0; j < B; j++)
            if (mx[i] < arr[IB + j])
            {
                mx[i] = arr[j + IB];
                cnt[i] = 1;
            }
            else if (mx[i] == arr[j + IB])
                cnt[i]++;
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end(), cmp);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(v, u);
        if (q.count({u, v}))
        {
            q.erase({u, v});
            if (!pr(u, v) && !pr(v, u))
            {
                upd(fir[v], last[v], -1);
                upd(fir[u], last[u], -1);
            }
            else
            {
                if (pr(v, u))
                    swap(v, u);
                int l = 0, r = g[u].size();
                while (r - l > 1)
                {
                    int mid = (r + l) / 2;
                    if (tin[g[u][mid]] <= tin[v])
                        l = mid;
                    else
                        r = mid;
                }
                u = g[u][l];
                upd(fir[1], last[1], -1);
                upd(fir[u], last[u], 1);
                upd(fir[v], last[v], -1);
            }
        }
        else
        {
            q.insert({u, v});
            if (!pr(u, v) && !pr(v, u))
            {
                upd(fir[v], last[v], 1);
                upd(fir[u], last[u], 1);
            } 
            else
            {
           //     cout << "mem" << endl;
                if (pr(v, u))
                    swap(v, u);
                int l = 0, r = g[u].size();
                while (r - l > 1)
                {
                    int mid = (r + l) / 2;
                    if (tin[g[u][mid]] <= tin[v])
                        l = mid;
                    else
                        r = mid;
                }
                u = g[u][l];
           //     cout << u << ' '  << v << ' ' << fir[u] << ' ' << last[u] << endl;
                upd(fir[1], last[1], 1);
              //  cout << " kek ";
                //for (int i = 1; i <= n; i++)
              //      cout << arr[i] << ' ';
               // cout << endl;
                upd(fir[u], last[u], -1);
            //     cout << " kek ";
              //  for (int i = 1; i <= n; i++)
                //    cout << arr[i] << ' ';
               // cout << endl;

                upd(fir[v], last[v], 1);
            //     cout << " kek ";
              //  for (int i = 1; i <= n; i++)
                //    cout << arr[i] << ' ';
           //     cout << endl;


            }

        }
        int ans = 0;
        int kek = q.size();
        for (int j = 0; j * B <= n + 5; j++)
            if (mx[j] == kek)
                ans += cnt[j];
        cout << ans << '\n';
    }
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}