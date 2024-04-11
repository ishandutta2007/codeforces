#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define m_p make_pair
#define inf 200000000000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c) {string tem(1, c); return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long

/////////////



signed main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif
    int t;
    cin >> t;
    while (t)
    {
        --t;
        int n, l, r;
        unsigned int x, y, z;
        cin >> n;
        int a[n];
        unsigned int b[n + 3];
        cin >> l >> r >> x >> y >> z >> b[0] >> b[1];
        int mo = (1ll << 32);
        for (int i = 2; i < n; ++i)
        {
            b[i] = ((((b[i - 2] * x) % mo) + ((b[i - 1] * y) % mo) + z) % mo + mo) % mo;
        }
        for (int i = 0; i < n; ++i)
        {
            a[i] = (b[i] % (r - l + 1)) + l;
        }
        int ans, fl = 0;
        int ma = a[n - 1];

        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] <= 0 )
            {
                if (ma > a[i])
                {
                    if (fl == 0)
                    {
                        fl = 1;
                        ans = a[i] * ma;
                    }
                    else
                        ans = min(ans, a[i] * ma);
                }
            }
            ma=max(ma,a[i]);
        }
        int mi=a[0];
        for (int i = 0 ; i <n; ++i)
        {
            if (a[i] >= 0 )
            {
                if (mi < a[i])
                {
                    if (fl == 0)
                    {
                        fl = 1;
                        ans = a[i] * mi;
                    }
                    else
                        ans = min(ans, a[i] * mi);
                }
            }
            mi=min(a[i],mi);
        }
        if (fl == 0)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
            cout << ans << "\n";
    }
}