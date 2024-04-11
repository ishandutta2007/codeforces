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

vector< pair<ll, ll> > a, b;
vector<ll> g;

int main()
{
    fastRead;
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    s += '1';
    int cur = 0, num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            cur++;
        else
        {
            num += cur / b;
            cur = 0;
        }
    }
    int ans = num - a + 1;
    cout << ans << endl;
    for (int i = 0; i < s.size() && ans > 0; i++)
    {
        if (s[i] == '0')
        {
            cur++;
            if (cur == b)
            {
                cout << i + 1 << " ";
                cur = 0;
                ans--;
            }
        }
        else
            cur = 0;
    }
    return 0;
}