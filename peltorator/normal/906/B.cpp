#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

ll nod1(ll a, ll b)
{
    return a ? nod1(b % a, a) : b;
}

ll nod(ll a, ll b)
{
    if (a > b)
        swap(a, b);
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
const ld eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

//vector<ll> a;

int used[MAXN];

int tt[MAXN];

vector<vector<int> > a;

void print(bool ok)
{
    int n = a.size();
    int m = a[0].size();
    if (!ok)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << a[i][j] << " ";
            cout << "\n";
        }
    else
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[j][i]--;
                int t = a[j][i] / m;
                int q = a[j][i] % m;
                cout << q * n + t + 1 << " ";
            }
            cout << "\n";
        }
    cout << endl;
    exit(0);
}

int main()
{
   // freopen("in.txt", "r", stdin);
    fastRead;
    int n, m;
    cin >> n >> m;
    bool ok = false;
    if (n > m)
        swap(n, m), ok = true;
    a.assign(n, vector<int>(m, 0));
    if (n * m == 1)
    {
        cout << "YES\n1" << endl;
        return 0;
    }
    if (n * m < 4 || (n == 2 && m == 2) || (n == 2 && m == 3))
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    if (m >= 6)
    {
        for (int i = 0; i < n; i++)
        {
            a[i].clear();
            if (i % 2)
            {
                for (int j = 1; j <= m; j += 2)
                    a[i].push_back(m * i + j);
                for (int j = 2; j <= m; j += 2)
                    a[i].push_back(m * i + j);
            }
            else
            {
                for (int j = 2; j <= m; j += 2)
                    a[i].push_back(m * i + j);
                for (int j = 1; j <= m; j += 2)
                    a[i].push_back(m * i + j);
            }
        }
        print(ok);
        return 0;
    }
    if (n == 1)
    {
        if (m == 4)
        {
            a[0][0] = 2;
            a[0][1] = 4;
            a[0][2] = 1;
            a[0][3] = 3;
            print(ok);
            return 0;
        }
        if (m == 5)
        {
            a[0][0] = 2;
            a[0][1] = 4;
            a[0][2] = 1;
            a[0][3] = 5;
            a[0][4] = 3;
            print(ok);
            return 0;
        }
    }
    if (n == 3 && m == 3)
    {
        cout << "5 1 9\n" << "3 7 2\n" << "8 6 4\n" << endl;
        return 0;
    }
    if (m == 4)
    {
        a[0][0] = 2;
        a[0][1] = 4;
        a[0][2] = 1;
        a[0][3] = 3;
        a[1][0] = 3 + 4;
        a[1][1] = 1 + 4;
        a[1][2] = 4 + 4;
        a[1][3] = 2 + 4;
    }
    if (m == 5)
    {
        a[0][0] = 2;
        a[0][1] = 4;
        a[0][2] = 1;
        a[0][3] = 5;
        a[0][4] = 3;
        a[1][0] = 3 + 5;
        a[1][1] = 1 + 5;
        a[1][2] = 5 + 5;
        a[1][3] = 2 + 5;
        a[1][4] = 4 + 5;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            a[i][j] = a[i - 2][j] + 2 * m;
    }
    print(ok);
    return 0;
}