#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

ll nod1(ll a, ll b)
{
    return (a ? nod1(b % a, a) : b);
}

ll nod(ll a, ll b)
{
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    return nod1(a, b);
}

ll nok(ll a, ll b)
{
    return a / nod(a, b) * b;
}

ll sum(vector<int> v)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += v[i];
    return ans;
}

ll sum(vector<ll> v)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += v[i];
    return ans;
}

bool letter(char c)
{
    return 'a' <= c && c <= 'z';
}

bool LETTER(char c)
{
    return 'A' <= c && c <= 'Z';
}

string intToStr1(ll n)
{
    return n ? intToStr1(n / 10) + (char)('0' + n % 10) : "";
}

string intToStr(ll n)
{
    return n ? intToStr(n) : "0";
}

ll strToInt(string s)
{
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans = 10 * ans + (s[i] - '0');
    return ans;
}

bool digit(char c)
{
    return '0' <= c && c <= '9';
}

bool prime(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

const ld zero = 0;
const ll null = 0;
const ll INF = 1e18;
const ll MOD = 1000000007;
const ld PI = atan2(0, -1);
const int MAXN = 200001;
const int F = 4000001;
const int N = MAXN;
const ld eps = 1e-8;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int tree[F];
int a[F];
/*
int __gcd(int x, int y)
{
    return nod(x, y);
}*/

void buildtree(int v, int l, int r)
{
    if (r < l)
        return;
    if (l == r)
    {
        tree[v] = a[r];
        return;
    }
    int mid = (r + l) / 2;
    buildtree(2 * v, l, mid);
    buildtree(2 * v + 1, mid + 1, r);
    tree[v] = __gcd(tree[2 * v], tree[2 * v + 1]);
}

int tf(int v, int l, int r, int ql, int qr, int t)
{
    if (r < l || ql > r || l > qr)
        return 0;
    if (tree[v] % t == 0)
        return 0;
    if (r == l)
        return 1;
   // cout << l << " " << r << " " << tree[v] << endl;
    int mid = (r + l) / 2;
    int ok = tf(2 * v, l, mid, ql, qr, t);
    if (ok > 1)
        return 2;
    return tf(2 * v + 1, mid + 1, r, ql, qr, t) + ok;
}

void tu(int v, int l, int r, int q, int val)
{
    if (q > r || q < l)
        return;
    if (r == l)
    {
        tree[v] = val;
        return;
    }
    int mid = (r + l) / 2;
    tu(2 * v, l, mid, q, val);
    tu(2 * v + 1, mid + 1, r, q, val);
    tree[v] = __gcd(tree[2 * v], tree[2 * v + 1]);
}

int main()
{
    //freopen("in.txt", "r", stdin);
   // fastRead;
    int n;
    //cin >> n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);//cin >> a[i];
    buildtree(1, 1, n);
    int q;
    scanf("%d", &q);//cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);//cin >> x;
        if (x == 1)
        {
            int l, r, b;
            scanf("%d %d %d", &l, &r, &b);//cin >> l >> r >> b;
            cout << (tf(1, 1, n, l, r, b) < 2 ? "YES" : "NO") << " ";
        }
        else
        {
            int a, b;
            scanf("%d %d", &a, &b);//cin >> a >> b;
            tu(1, 1, n, a, b);
        }
    }
    return 0;
}