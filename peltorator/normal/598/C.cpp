#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
typedef vector<int> number;
typedef long long ll;
 
const ll BASE = 10;

number makeNumber(ll n)
{
    number a;
    while (n)
    {
        a.push_back(n % BASE);
        n /= BASE;
    }
    if (!a.size())
        a.push_back(0);
    return a;
}
 
number removeZeros(number a)
{
    for (int i = a.size() - 1; !a[i] && i; i--)
        if (a[i] == 0)
            a.pop_back();
    return a;
}
 
int compare(number a, number b)
{
    a = removeZeros(a);
    b = removeZeros(b);
    if (a.size() != b.size())
        return a.size() > b.size() ? 1 : -1;
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i])
            return a[i] > b[i] ? 1 : -1;
    return 0;
}
 
number sum(number a, number b)
{
    if (compare(a, b) == -1)
        swap(a, b);
    number c(a.size(), 0);
    int trans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        c[i] = a[i] + trans;
        if (i < b.size())
            c[i] += b[i];
        trans = c[i] / BASE;
        c[i] %= BASE;
    }
    c.push_back(trans);
    return removeZeros(c);
}

number multiply(number a, number b)
{
    number c(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    for (int i = 0; i + 1 < c.size(); i++)
    {
        c[i + 1] += c[i] / BASE;
        c[i] %= BASE;
    }
    return removeZeros(c);
}

vector<pair<int, int> > q;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second >= 0 && b.second < 0)
        return 1;
    if (a.second < 0 && b.second >= 0)
        return 0;
    if (a.second == 0 && b.second == 0)
        return (a.first > 0 && b.first < 0);
    if (a.second == 0 && a.first > 0)
        return 1;
    if (b.second == 0 && b.first > 0)
        return 0;
    if (a.second == 0)
        return b.second < 0;
    if (b.second == 0)
        return a.second > 0;
    return a.first * b.second - a.second * b.first > 0;
}

const int N = 200001, M = 100000;

unordered_map<int, int> p[N];

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << "1 2";
        return 0;
    }
    q.resize(n);
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second, p[M + q[i].first][q[i].second] = i + 1;
    sort(q.begin(), q.end(), cmp);
    ll best = -1e17;
    ll a = -1, b = -1;
    for (int i = 0; i < n; i++)
    {
        ll x = q[i].first, y = q[i].second, xx = q[(i + 1) % n].first, yy = q[(i + 1) % n].second;
        if (x * yy - xx * y <= 0)
            continue;
        ll cur = (x * xx + y * yy);
        if (a == -1 || (cur >= 0 && best <= 0))
        {
            best = cur;
            a = i;
            b = (i + 1) % n;
            continue;
        }
        if (cur <= 0 && best >= 0)
            continue;
        ll X = q[a].first, Y = q[a].second, XX = q[b].first, YY = q[b].second;
        number kek = multiply(makeNumber(cur * cur), makeNumber((X * X + Y * Y) * (XX * XX + YY * YY)));
        number mem = multiply(makeNumber(best * best), makeNumber((x * x + y * y) * (xx * xx + yy * yy))); 
        if ((compare(mem, kek) == -1 && cur > 0) || (compare(mem, kek) == 1 && cur < 0))
        {
            best = cur;
            a = i;
            b = (i + 1) % n;
        }
    }
    int x = q[a].first, y = q[a].second, xx = q[b].first, yy = q[b].second;
    cout << p[M + x][y] << " " << p[M + xx][yy];
    return 0;
}