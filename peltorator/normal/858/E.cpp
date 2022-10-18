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

ll nod1(int a, int b)
{
    return a ? nod1(b % a, a) : b;
}

ll nod(int a, int b)
{
    if (a > b)
        swap(a, b);
    return nod1(a, b);
}

ll gcd(int a, int b)
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
    return n ? intToStr1(n) : "0";
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

vector<string> a, b;
vector<string> aw, bw;
vector<int> ae, be;
vector<int> used;

int n;

bool check(string s)
{
    bool ok = true;
    if (s[0] == '0')
        ok = false;
    for (int i = 0; i < s.size(); i++)
        if (!digit(s[i]))
           ok = false;
    return ok && strToInt(s) <= n;
}

vector<pair<string, string> > q;



int main()
{
   //freopen("in.txt", "r", stdin);
   // cout << nok(99999999, 100000000);
   // return 0;
	fastRead;
    cin >> n;
    used.assign(n + 1, 0);
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        if (x)
        {
            e++;
            a.push_back(s);
        }
        else
        {
            b.push_back(s);
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        string s = a[i];
        bool ok = check(s);
        if (ok && strToInt(s) > e)
            aw.push_back(s);
        if (ok)
            used[strToInt(s)] = 1;
    }
    for (int i = 0; i < b.size(); i++)
    {
        string s = b[i];
        bool ok = check(s);
        if (ok && strToInt(s) <= e)
            bw.push_back(s);
        if (ok)
            used[strToInt(s)] = 1;
    }
    for (int i = 1; i <= e; i++)
        if (!used[i])
            ae.push_back(i);
    for (int i = e + 1; i <= n; i++)
        if (!used[i])
            be.push_back(i);
    int ans = 0;
    bool mem = false;
    if (bw.size() + aw.size() > 0 && ae.size() + be.size() == 0)
    {
        be.push_back(strToInt(aw.back()));
        q.push_back(make_pair(aw.back(), "0"));
        for (int i = 0; i < a.size(); i++)
            if (a[i] == aw.back())
                a[i] = "0";
        aw.pop_back();
        mem = 1;
    }
    while (aw.size() + bw.size())
    {
        //cout << aw.back() << " " << ae.back() << " " << intToStr(ae.back()) << " ";
        //cout << aw.size() << " " << ae.size() << " " << bw.size() << " n " << be.size() << endl;
        if (ae.size() && aw.size())
        {
            q.push_back(make_pair(aw.back(), intToStr(ae.back())));
            be.push_back(strToInt(aw.back()));
            aw.pop_back();
            ae.pop_back();
          //  return 0;
        }
        else
        {
            q.push_back(make_pair(bw.back(), intToStr(be.back())));
            ae.push_back(strToInt(bw.back()));
            bw.pop_back();
            be.pop_back();
        }
    }
   // return 0;
    for (int i = 0; i < a.size(); i++)
        if (!check(a[i]))
        {
            q.push_back(make_pair(a[i], intToStr(ae.back())));
            ae.pop_back();
        }
    for (int i = 0; i < b.size(); i++)
        if (!check(b[i]))
        {
            q.push_back(make_pair(b[i], intToStr(be.back())));
            be.pop_back();
        }
    cout << q.size();
    for (int i = 0; i < q.size(); i++)
    {
        cout << "\n" << "move " << q[i].fi << " " << q[i].se;
    }
    return 0;
}