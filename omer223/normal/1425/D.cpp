/*
                            . .  ,  ,
                            |` \/ \/ \,',
                            ;          ` \/\,.
                           :               ` \,/
                           |                  /
                           ;                 :
                          :                  ;
                          |      ,---.      /
                         :     ,'     `,-._ \
                         ;    (   o    \   `'
                       _:      .      ,'  o ;
                      /,.`      `.__,'`-.__,
                      \_  _               \
                     ,'  / `,          `.,'
               ___,'`-._ \_/ `,._        ;
            __;_,'      `-.`-'./ `--.____)
         ,-'           _,--\^-'
       ,:_____      ,-'     \
      (,'     `--.  \;-._    ;
      :    Y      `-/    `,  :
      :    :       :     /_;'
      :    :       |    :
       \    \      :    :
        `-._ `-.__, \    `.
           \   \  `. \     `.
         ,-;    \---)_\ ,','/
         \_ `---'--'" ,'^-;'
         (_`     ---'" ,-')
         / `--.__,. ,-'    \
-hrr-    )-.__,-- ||___,--' `-.
        /._______,|__________,'\
        `--.____,'|_________,-'

                             __
                   _ ,___,-'",-=-.
       __,-- _ _,-'_)_  (""`'-._\ `.
    _,'  __ |,' ,-' __)  ,-     /. |
  ,'_,--'   |     -'  _)/         `\
,','      ,'       ,-'_,`           :
,'     ,-'       ,(,-(              :
     ,'       ,-' ,    _            ;
    /        ,-._/`---'            /
   /        (____)(----. )       ,'
  /         (      `.__,     /\ /,
 :           ;-.___         /__\/|
 |         ,'      `--.      -,\ |
 :        /            \    .__/
  \      (__            \    |_
   \       ,`-, *       /   _|,\
    \    ,'   `-.     ,'_,-'    \
   (_\,-'    ,'\")--,'-'       __\
    \       /  // ,'|      ,--'  `-.
     `-.    `-/ \'  |   _,'         `.
        `-._ /      `--'/             \
-hrr-      ,'           |              \
          /             |               \
       ,-'              |               /
      /                 |             -'

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 

using namespace __gnu_pbds;
using namespace std;


typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpi> vvpi;
typedef vector<vpl> vvpl;
typedef set<int> si;
typedef multiset<int> msi;
typedef set<ll> sl;
typedef multiset<ll> msl;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


typedef long double ld;
#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repk(i, k, n) for(int i = k; i < n; ++i)

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define gcd std::__detail::__gcd
#define lcm std::__detail::__lcm

const int INFI = 1e9 + 5;
const ll INFL = 4e18 + 5;

template<class T> void aread(T* arr, int ___n)
{
    rep(i, ___n)
    {
        cin >> arr[i];
    }
}


// LIORZ LIORZ LIORZ LIORZ LIORZ
















#define YA "Ya"
#define NO "Tidak"
const ll maxn = 2e3 + 5;
const ll maxc = 2e3 + 5;
const ll mod = 1e9 + 7;
ll n, m, r;
int pre[maxc][maxc];
int board[maxc][maxc];
pi pts[maxn];
ll fact[maxc];
ll invf[maxc];
ll vals[maxn];
ll bexp(ll b, ll p)
{
    ll curr = b;
    ll res = 1;
    while(p)
    {
        if(p%2)
        {
            res *= curr;
            res %=mod;
        }
        curr *= curr;
        curr %= mod;
        p /= 2;
    }
    return res;
}
ll invm(ll i)
{
    return bexp(i, mod-2);
}
void initcalc()
{
    fact[0] = 1;
    fact[1] = 1;
    invf[0] = 1;
    invf[1] = 1;
    for(ll i = 2; i < maxn; ++i)
    {
        fact[i] = (i * fact[i-1]) % mod;
        invf[i] = invm(fact[i]);
    }
}
void init()
{
    cin >> n >> m >> r;
    rep(i, n)
    {
        cin >> pts[i].se >> pts[i].fi;
        board[pts[i].fi][pts[i].se] = 1;
        cin >> vals[i];
    }
    for(int i = 1; i < maxc; ++i)
    {
        for(int j = 1; j < maxc; ++j)
        {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + board[i][j];
        }
    }
    initcalc();
}
ll chs(ll am, ll k)
{
    if(k>am) return 0;
    return (((fact[am] * invf[k]) % mod) * invf[am-k]) % mod;
}
ll query(const pi l, const pi r)
{
    // L - BL, R - UR
    if(r.fi < l.fi || r.se < l.se) return 0;
    return pre[r.fi][r.se] - pre[r.fi][l.se-1] - pre[l.fi-1][r.se] + pre[l.fi-1][l.se-1];
}
void solve()
{
    init();
    ll res = 0;
    for(int i = 0; i < n; ++i)
    {
        pi a = pts[i];
        pi ra = {min(maxc-1LL, a.fi+r), min(maxc-1LL, a.se+r)};
        pi la = {max(1LL, a.fi-r), max(1LL, a.se-r)};
        ll ca = query(la, ra);
        ll sfct = (chs(n, m) - chs(n-ca, m) + mod) % mod;
        res += (sfct * ((vals[i] * vals[i]) % mod)) % mod;
        res %= mod;
        ll oca = ca;
        for(int j = i+1; j < n; ++j)
        {
            ca = oca;
            pi b = pts[j];
            pi lb = {max(1LL, b.fi-r), max(1LL, b.se-r)};
            pi rb = {min(maxc-1LL, b.fi+r), min(maxc-1LL, b.se+r)};
            ll cb = query(lb, rb);
            pi lcut = {max(la.fi, lb.fi), max(la.se, lb.se)};
            pi rcut = {min(ra.fi, rb.fi), min(ra.se, rb.se)};
            ll cut = query(lcut, rcut);
            ca -= cut;
            cb -= cut;
            // pick 1 from cut and dont care about res or 1 from ca one from cb and nothing from cut
            ll fct = chs(n, m) - chs(n-cut, m);
            fct += (chs(n-cut, m) - (chs(n-cut-ca, m) + chs(n-cut-cb, m) - chs(n-cut-ca-cb, m)) + 4 * mod) % mod;
            res += (2LL * ((fct * ((vals[i] * vals[j]) % mod)) % mod)) % mod;
            res %= mod;
            
        }
    }
    cout << res << endl;

}




























signed main()
{
    GOGOGO
    cout << fixed << setprecision(9);
    int t=1;
    #ifdef BRUH_WHY_TESTCASES
            cin >> t;
    #endif
    while(t--)
    {
        solve();
    }
    BYEBYE
}

/* PLEASE READ THIS
* N = 1
* GUESS A!!!!!!!
* DO SOMETHING INSTEAD OF NOTHING
*/