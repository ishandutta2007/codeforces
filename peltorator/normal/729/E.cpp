#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
#define _GLIBCXX_DEBUG
#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(), v.end()
#define randInt ((rand() << 15) | rand())
#define For(i, n) for (int i = 0; i < n; i++)
#define whatIs(x) cerr << #x << " is " << x << endl
#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second

int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

string int_to_str_easy(ll n)
{
    return n ? int_to_str_easy(n / 10) + (char)('0' + n % 10) : "";
}

long long sum(vector<int> v)
{
    int ans = 0;
    For(i, v.size())
        ans += v[i];
    return ans;
}

bool prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool letter(char c)
{
    return 'a' <= c && c <= 'z';
}
bool LETTER(char c)
{
    return 'A' <= c && c <= 'Z';
}
bool digit(char c)
{
    return ('0' <= c && c <= '9');
}

const ld pi = 3.141592653589793238462643383279;
const ld eps = 1e-8;
const ld zero = 0;
const ll null = 0;
const ll INF = 1e18;
//const int INF = 1e9;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAXN = 200001;
const int MAXM = 1001;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<int> a;

int main()
{
    fastRead;
    int n, s;
    cin >> n >> s;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        if (a[0] == 0)
            cout << a[0];
        else
            cout << 1;
        return 0;
    }
    int ans = 0;
    if (a[s - 1] != 0)
    {
        ans++;
        a[s - 1] = 0;
    }
    sort(all(a));
    if (a[a.size() - 1] == 0)
    {
        cout << a.size() - 1 + ans;
        return 0;
    }
    int curr = a.size() - 1, curl = 1;
    for (int i = 1; i <= curr; i++)
    {
        if (a[i] == 0)
            continue;
        if (a[i] - a[i - 1] > 1)
        {
            int t = a[i - 1] + 1;
            while (t < a[i] && a[curl] == 0)
            {
                a[curl] = t;
                curl++;
                t++;
                ans++;
            }
            while (i < curr && t < a[i])
            {
                t++;
                a[curr] = a[i - 1] + 1;
                curr--;
                ans++;
            }
            if (t < a[i] && i == curr)
            {
                a[curr] = t;
                ans++;
            }
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
            ans++;
    }
    cout << ans - 1;
    return 0;
}