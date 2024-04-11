#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(239);

#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define ob pop_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 2e6;
const ll INF = 3e18;

ll ans[N];
ll arr[N];

ll a[N], b[N], amx[N], bmx[N], mem[N], memr[N];
int a_sz, b_sz;

void push(ll x)
{
    b[b_sz] = x;
    bmx[b_sz] = x;
    if (b_sz)
        bmx[b_sz] = max(bmx[b_sz - 1], x);
    b_sz++;
}

ll get()
{
    ll answ = -INF;
    if (a_sz)
        answ = amx[a_sz - 1];
    if (b_sz)
        answ = max(answ, bmx[b_sz - 1]);
    return answ;
}

void pop()
{
    if (a_sz)
    {
        a_sz--;
        return;
    }
    while (b_sz)
    {
        ll x = b[b_sz - 1];
        a[a_sz] = x;
        amx[a_sz] = x;
        if (a_sz)
            amx[a_sz] = max(amx[a_sz - 1], x);
        a_sz++;
        b_sz--;
    }
    a_sz--;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int w;
    cin >> w;
    for (int i = 0; i < w; i++)
        ans[i] = 0;
    //int m = w / 2 - 5;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        for (int ii = 0; ii < l; ii++)
            cin >> arr[ii];
        if (true)//false && l >= m)
        {
            a_sz = b_sz = 0;
            int curl = 0, curr = -1;
            for (int j = 0; j < w;)
            {
                ll cur = -INF;
                int R;
                if (l <= j)
                {
                    cur = 0;
                    R = l - 1;
                }
                else
                    R = j;
                int L;
                if (j + l < w)
                {
                    cur = 0;
                    L = 0;
                }
                else
                    L = l - (w - j);
                while (curr < R)
                    push(arr[++curr]);
                while (curl < L)
                {
                    pop();
                    curl++;
                }
                cur = max(cur, get());
                ans[j] += cur;
                if (j + 1 != l)
                {
                    j++;
                }
                else
                {
                    j = max(l, w - l);
                }
            }
/*
            for (int j = w - 1; j >= max(w - l, l); j--)
            {
                ll cur = -INF;
                int R;
                if (l <= j)
                {
                    cur = 0;
                    R = l - 1;
                }
                else
                    R = j;
                int L;
                if (j + l < w)
                {
                    cur = 0;
                    L = 0;
                }
                else
                    L = l - (w - j);
                while (curl > L)
                    push(arr[--curr]);
                while (curr > R)
                {
                    pop();
                    curr--;
                }
                cur = max(cur, get());
                ans[j] += cur;
            }
*/
            ll cur = -INF;
            for (int ii = 0; ii < l; ii++)
            {
                cur = max(cur, arr[ii]);
               // ll tt = cur;
               // if (w - ii - 1 >= l)
               //     tt = max(tt, 0LL);
               // ans[ii] += tt;
            }
            mem[l] += max(cur, 0LL);
        }
        else
        {
            ll cur = -INF;
            for (int ii = 0; ii < l; ii++)
            {
                cur = max(cur, arr[ii]);
                ll tt = cur;
                if (w - ii - 1 >= l)
                    tt = max(tt, 0LL);
                ans[ii] += tt;
            }
            mem[l] += max(cur, 0LL);
            cur = -INF;
            if (l < w)
                cur = 0;
            for (int ii = l - 1; ii >= 0; ii--)
            {
                cur = max(cur, arr[ii]);
                ll tt = cur;
                if (ii >= l)
                    tt = max(tt, 0LL);
                ans[w - (l - ii)] += tt;
            }
        }
    }
    for (int i = 1; i <= w; i++)
        mem[i] += mem[i - 1];
    for (int i = 0; i < w; i++)
    {
        cout << ans[i] + mem[min(i, w - i - 1)] << ' ';
    }
    cout << '\n';
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    while (TET--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}