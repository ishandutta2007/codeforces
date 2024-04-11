#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <unordered_map>
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

int gcd(int a, int b)
{
    if (a > b)
        swap(a, b);
    return nod1(a, b);
}

int nok(int a, int b)
{
    return a / nod(a, b) * b;
}

ll sum(vector<ll> v)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += v[i];
    return ans;
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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const ll P = 239, Q = 1000000007, R = 37, S = 1000000009;

unordered_map<ll, unordered_set<ll> > q;

vector<string> a;

int main()
{
    //freopen("in.txt", "r", stdin);
	fastRead;
    int n;
    cin >> n;
    for (int it = 0; it < n; it++)
    {
        string s;
        cin >> s;
        a.push_back(s);
        for (int i = 0; i < (int)s.size(); i++)
        {
            string t = "";
            ll z = 0;
            for (int j = i; j < (int)s.size(); j++)
            {
                t.push_back(s[j]);
                z = 11LL * z + ((s[j] - '0') + 1);
                q[z].insert(it);
            }
        }
    }
    for (int it = 0; it < n; it++)
    {
        string ans = a[it];
        for (int i = 0; i < (int)a[it].size(); i++)
        {
            string t = "";
            ll z = 0;
            for (int j = i; j < (int)a[it].size(); j++)
            {
                t.push_back(a[it][j]);
                z = 11LL * z + ((a[it][j] - '0') + 1);
                if (q[z].size() == 1 && (int)t.size() < (int)ans.size())
                    ans = t;
                if ((int)t.size() >= (int)ans.size())
                    break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}