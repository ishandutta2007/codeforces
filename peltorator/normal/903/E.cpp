#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <set>
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
const int N = MAXN;
const ld eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

string s[N];

vector<int> pos[N];
int kek[N];
vector<int> cur;
vector<int> mem;
int main()
{
    //freopen("in.txt", "r", stdin);
    fastRead;
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> s[i];
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            if (s[i][j] != s[0][j])
                pos[i].push_back(j);
        if (pos[i].size() > 4)
        {
            cout << -1;
            return 0;
        }
    }
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        kek[s[0][i] - 'a']++;
        if (kek[s[0][i] - 'a'] > 1)
            ok = true;
    }
    int t = 1;
    while (t < k && pos[t].size() == 0)
        t++;
    if (t == k)
    {
        swap(s[0][0], s[0][1]);
        cout << s[0];
        return 0;
    }
    swap(pos[1], pos[t]);
    swap(s[1], s[t]);
    for (int _ = 0; _ < pos[1].size(); _++)
    {
        int i = pos[1][_];
        for (int j = 0; j < n; j++)
            if (j != i)
            {
               // cout << i << " " << j << endl;
                bool good = true;
                swap(s[0][i], s[0][j]);
                for (int l = 1; good && l < k; l++)
                {
                    cur.clear();
                    for (int b = 0; b < pos[l].size(); b++)
                        if (s[l][pos[l][b]] != s[0][pos[l][b]])
                            cur.push_back(pos[l][b]);
                    if (s[l][i] != s[0][i])
                        cur.push_back(i);
                    if (s[l][j] != s[0][j])
                        cur.push_back(j);
                    sort(cur.begin(), cur.end());
                    mem.clear();
                    if (cur.size())
                        mem.push_back(cur[0]);
                    for (int i = 1; i < cur.size(); i++)
                        if (cur[i] != cur[i - 1])
                            mem.push_back(cur[i]);
                    cur = mem;
                    if (cur.size() == 2 || (cur.size() == 0 && ok))
                    {
                        if (cur.size() == 2)
                        {
                            swap(s[l][cur[0]], s[l][cur[1]]);
                            if (s[0][cur[1]] != s[l][cur[1]] || s[0][cur[0]] != s[l][cur[0]])
                                good = false;
                            swap(s[l][cur[0]], s[l][cur[1]]);
                        }
                    }
                    else
                        good = false;

                }
                if (good)
                {
                    cout << s[0];
                    return 0;
                }
                swap(s[0][i], s[0][j]);
            }
    }
    swap(s[0], s[1]);
    for (int i = 0; i < k; i++)
        pos[i].clear();
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            if (s[i][j] != s[0][j])
                pos[i].push_back(j);
        if (pos[i].size() > 4)
        {
            cout << -1;
            return 0;
        }
    }
    for (int _ = 0; _ < pos[1].size(); _++)
    {
        int i = pos[1][_];
        for (int j = 0; j < n; j++)
            if (j != i)
            {
                bool good = true;
                swap(s[0][i], s[0][j]);
                for (int l = 1; good && l < k; l++)
                {
                    cur.clear();
                    for (int b = 0; b < pos[l].size(); b++)
                        if (s[l][pos[l][b]] != s[0][pos[l][b]])
                            cur.push_back(pos[l][b]);
                    if (s[l][i] != s[0][i])
                        cur.push_back(i);
                    if (s[l][j] != s[0][j])
                        cur.push_back(j);
                    sort(cur.begin(), cur.end());
                    mem.clear();
                    if (cur.size())
                        mem.push_back(cur[0]);
                    for (int i = 1; i < cur.size(); i++)
                        if (cur[i] != cur[i - 1])
                            mem.push_back(cur[i]);
                    cur = mem;
                    if (cur.size() == 2 || (cur.size() == 0 && ok))
                    {
                        if (cur.size() == 2)
                        {
                            swap(s[l][cur[0]], s[l][cur[1]]);
                            if (s[0][cur[1]] != s[l][cur[1]] || s[0][cur[0]] != s[l][cur[0]])
                                good = false;
                            swap(s[l][cur[0]], s[l][cur[1]]);
                        }
                    }
                    else
                        good = false;

                }
                if (good)
                {
                    cout << s[0];
                    return 0;
                }
                swap(s[0][i], s[0][j]);
            }
    }
    cout << -1;
    return 0;
}