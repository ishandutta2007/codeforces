#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

struct seg
{
    ll beg, len;
    seg():
        beg(0), len(0) {}
    seg(ll beg, ll len):
        beg(beg), len(len) {}
};

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        arr[i] = x - i;
    }
    vector<seg> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.back().beg > arr[i])
        {
            st.push_back(seg(arr[i], 1));
            continue;
        }
        st.back().len++;
        ll diff = arr[i] - st.back().beg;
        while (diff > 0)
        {
            if (sz(st) > 1)
            {
                if (diff >= st.back().len)
                {
                    diff -= st.back().len;
                    st[sz(st) - 2].len += st.back().len;
                    st.pop_back();
                }
                else
                {
                    st.back().len -= diff;
                    st[sz(st) - 2].len += diff;
                    diff = 0;
                }
            }
            else
            {
                if (diff >= st.back().len)
                {
                    st.back().beg += diff / st.back().len;
                    diff %= st.back().len;
                }
                else
                {
                    st.push_back(seg(st.back().beg, st.back().len - diff));
                    st[sz(st) - 2].beg++;
                    st[sz(st) - 2].len = diff;
                    diff = 0;
                }
            }
        }
    }
    for (int i = 0, pos = 0; i < sz(st); i++)
        for (int j = 0; j < st[i].len; j++)
            arr[pos] = st[i].beg + pos, pos++;
    for (ll i : arr)
        cout << i << ' ';
    cout << '\n';
    return 1;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}