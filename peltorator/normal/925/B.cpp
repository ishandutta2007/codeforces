/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//permanent constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-10;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 9;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//easy functions
template< typename T >
inline T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
ll power(ll a, int k)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1) ans = (ans * a) % MOD;
        ans = (ans * ans) % MOD;
        k >>= 1;
    }
    return ans;
}

//random
mt19937 rnd(239);

//constants
const int M = 3 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

// Code starts here

int n;
vector<pair<ll, int> > x;
ll c[M];
int id[M];
vector<pair<ll, int> > al;
vector<int> ans[two];

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    int x1, x2;
    cin >> n >> x1 >> x2;
    x.push_back(make_pair(x1, 0));
    x.push_back(make_pair(x2, 1));
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        al.push_back(make_pair(c[i], i));
    sort(al.begin(), al.end());
    for (int i = 0; i < n; i++)
        c[i] = al[i].first, id[i] = al[i].second;
    for (int i = 0; i < 2; i++)
    {
        int mn = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if ((ll)(n - i) * c[i] >= x[1].first)
            {
                mn = i;
                break;
            }
        }
        if (mn == n)
        {
            swap(x[0], x[1]);
            continue;
        }
        int xn = mn;
        for (int i = mn - 1; i >= 0; i--)
        {
            if ((ll)(mn - i) * c[i] >= x[0].first)
            {
                xn = i;
                break;
            }
        }
        if (xn == mn)
        {
            swap(x[0], x[1]);
            continue;
        }
        for (int i = xn; i < mn; i++)
            ans[x[0].second].push_back(id[i]);
        for (int i = mn; i < n; i++)
            ans[x[1].second].push_back(id[i]);
        cout << "Yes\n";
        cout << ans[0].size() << " " << ans[1].size() << "\n";
        sort(ans[0].begin(), ans[0].end());
        for (int i : ans[0])
            cout << i + 1 << " ";
        cout << "\n";
        sort(ans[1].begin(), ans[1].end());
        for (int i : ans[1])
            cout << i + 1 << " ";
        cout << "\n";
        return 0;
    }
    cout << "No";
    return 0;
}