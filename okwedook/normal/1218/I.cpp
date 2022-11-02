#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, sh;
vector<vector<ll>> a, b;
vector<ll> v;
bool viv = false;

void read(vector<vector<ll>>& m)
{
m.resize(n);
for (auto& l : m)
    {
    string s;
    cin >> s;
    for (auto sy : s)
        l.push_back(sy - '0');
    }
}

void read(vector<ll>& m)
{
string s;
cin >> s;
for (auto sy : s)
    m.push_back(sy - '0');
}

void bad()
{
cout << -1;
exit(0);
}

bool same(vector<vector<ll>> a, vector<vector<ll>> b)
{
if (viv)
    {
    cout << "Cmp " << '\n';
    for (auto i : a)
        {
        for (ll j : i)
            cout << j << ' ';
        cout << endl;
        }
    for (auto i : b)
        {
        for (ll j : i)
            cout << j << ' ';
        cout << endl;
        }
    }
for (ll i = 0; i < n; i++)
    for (ll j = 0; j < n; j++)
        if (a[i][j] != b[i][j])
            return false;
return true;
}

vector<vector<ll>> shift(vector<vector<ll>> m, ll k)
{
vector<vector<ll>> res;
res.resize(n);
for (auto& l : res)
    l.resize(n);
for (ll i = 0; i < n; i++)
    for (ll j = 0; j < n; j++)
        res[i][j] = m[(i + k) % n][(j + k) % n];
return res;
}

vector<ll> shift(vector<ll> m, ll k)
{
vector<ll> res;
res.resize(n);
for (ll i = 0; i < n; i++)
    res[i] = m[(i + k) % n];
return res;
}

vector<ll> shifting(vector<ll> m, ll k)
{
vector<ll> res;
for (auto i : m)
    res.push_back((i + k) % n);
return res;
}

void shift_all()
{
ll pl = -1;
for (ll i = 0; i < n; i++)
    if (v[i])
        pl = i;
if (pl == -1 && !same(a, b))
    bad();
sh = pl;
if (viv)
    cout << "Shift by " << sh << endl;
a = shift(a, sh);
b = shift(b, sh);
v = shift(v, sh);
}

void write(vector <ll> r, vector <ll> c)
{
r = shifting(r, sh);
c = shifting(c, sh);

cout << r.size() + c.size() << endl;
for (auto i : r)
    cout << "row " << i << '\n';
for (auto i : c)
    cout << "col " << i << '\n';
cout << endl;
exit(0);
}

void check(bool r0, bool c0)
{
if (viv)
    cout << "go to check " << r0 << ' ' << c0 << endl;


vector <ll> rx;
vector <ll> cx;
auto la = a;
if (r0)
    {
    rx.push_back(0);
    for (ll i = 0; i < n; i++)
        la[0][i] ^= v[i];
    }
if (c0)
    {
    cx.push_back(0);
    for (ll i = 0; i < n; i++)
        la[i][0] ^= v[i];
    }

vector <ll> wrx, wcx;

for (ll i = 1; i < n; i++)
    {
    if (la[0][i] != b[0][i])
        wcx.push_back(i);
    if (la[i][0] != b[i][0])
        wrx.push_back(i);
    }


if (viv)
    {
    cout << "Columns: ";
    for (auto i : wcx)
        cout << i << ' ';
    cout << endl;
    cout << "Rows: ";
    for (auto i : wrx)
        cout << i << ' ';
    cout << endl;
    }

for (auto i : wrx)
    {
    for (ll j = 0; j < n; j++)
        la[i][j] ^= v[j];
    }
for (auto j : wcx)
    {
    for (ll i = 0; i < n; i++)
        la[i][j] ^= v[i];
    }

if (viv)
    {
    for (ll i = 0; i < n; i++)
        {
        for (ll j = 0; j < n; j++)
            cout << la[i][j] << ' ';
        cout << endl;
        }
    }


while (wrx.size())
    rx.push_back(wrx.back()), wrx.pop_back();
while (wcx.size())
    cx.push_back(wcx.back()), wcx.pop_back();

if (same(la, b))
    write(rx, cx);

}




int main()
{
//viv = true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin >> n;
read(a);
read(b);
read(v);
shift_all();



for (ll i = 0; i < 4; i++)
    check(i & 1, (i >> 1) & 1);
bad();


    return 0;
}
/**
3
000
000
000
001
101
100
101


**/