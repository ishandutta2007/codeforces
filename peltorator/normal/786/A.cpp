#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

int nod1(int a, int b)
{
    return a ? nod1(b % a, a) : b;
}

int nod(int a, int b)
{
    if (a > b)
        swap(a, b);
    return nod1(a, b);
}

int nok(int a, int b)
{
    return a / __gcd(a, b) * b;
}

ll sum(vector<int> v)
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
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

vector<ll> g[MAXN], w[MAXN], used[2];
vector<int> a[2], T[2];
int n;

int dfs(int hum, int v)
{
    if (used[hum][v] != 0)
        return 0;
    used[hum][v] = 3;
    for (int i = 0; i < a[hum].size(); i++)
    {
        int t = (v + a[hum][i]) % n;
        dfs(!hum, t);
        if (used[!hum][t] == 2)
            used[hum][v] = 1;
        if (used[!hum][t] == 3 && used[hum][v] != 1)
            used[hum][v] = -1;
        if (used[!hum][t] == -1 && used[hum][v] != 1)
            used[hum][v] = -1;
    }
    if (used[hum][v] == 3)
        used[hum][v] = 2;
    return 0;
}

int main()
{
    fastRead;
    cin >> n;
    int k1;
    cin >> k1;
    a[0].resize(k1);
    for (int i = 0; i < k1; i++)
    {
        cin >> a[0][i];
    }
    int k2;
    cin >> k2;
    a[1].resize(k2);
    for (int i = 0; i < k2; i++)
    {
        cin >> a[1][i];
    }
    T[1].assign(n, 0);
    T[0].assign(n, 0);
    used[0].assign(n, 0);
    used[1].assign(n, 0);
    used[0][0] = 2;
    used[1][0] = 2;
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({1, 0});
    while (!q.empty())
    {
        int hum = q.front().first, v = q.front().second;
        q.pop();
        for (int i = 0; i < a[!hum].size(); i++)
        {
            int t = (v + n - a[!hum][i]) % n;
            if (!used[!hum][t])
            {
                T[!hum][t]++;
                if (used[hum][v] == 2 || T[!hum][t] == a[!hum].size())
                {
                    used[!hum][t] = (used[hum][v] == 1 ? 2 : 1);
                    q.push({!hum, t});
                }
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < n; j++)
            cout << (used[i][j] == 1 ? "Win" : (used[i][j] == 2 ? "Lose" : "Loop")) << " ";
        cout << endl;
    }
    return 0;
}