#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long m, h1, a1, x1, y1, h2, a2, x2, y2, t1, p1, t2, p2;
long long vst[1000006];

pair<pair<long long, long long>, bool> solve (long long h, long long a, long long x, long long y)
{
    reset(vst, 0);
    vst[h] = 1;
    long long tmp = h;
    long long t = -1;
    while (1) {
        long long nex = (tmp * x + y) % m;
        if (vst[nex])
        {
            bool flag = false;
            if (t + 1 >= vst[nex]) flag = true;
            return {{t, vst[tmp] - vst[nex] + 1}, flag};
        }
        vst[nex] = 1 + vst[tmp];
        tmp = nex;
        if (tmp == a) t = vst[tmp] - 1;
    }
}

// a x + b y = gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}


// Inverse module a^-1 % m with a and m coprime
long long inverseMod(long long a, long long m) {
  long long x, y;
  extgcd(a, m, x, y);
  return (x + m) % m;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
    auto p = solve(h1, a1, x1, y1);
    t1 = p._1._1;
    p1 = p._1._2;
    bool flag1 = p._2;
    p = solve(h2, a2, x2, y2);
    t2 = p._1._1;
    p2 = p._1._2;
    bool flag2 = p._2;
    if (t1 == -1 || p1 == -1 || t2 == -1 || p2 == -1)
    {
        cout << -1;
        return 0;
    }
    if (!flag1 && !flag2)
    {
        if (t1 == t2) cout << t1;
        else cout << -1;
        return 0;
    }
    if (!flag1)
    {
        if (t1 >= t2 && (t1 - t2) % p2 == 0) cout << t1;
        else cout << -1;
        return 0;
    }
    if (!flag2)
    {
        if (t2 >= t1 && (t2 - t1) % p1 == 0) cout << t2;
        else cout << -1;
        return 0;
    }
    if (t1 > t2)
    {
        swap (t1, t2);
        swap (p1, p2);
    }
    //cout << t1 << ' ' << p1 << endl;
    //cout << t2 << ' ' << p2 << endl;
    long long tmp = __gcd(p1, p2);
    long long dt = t2 - t1;
    if (dt % tmp)
    {
        cout << -1;
        return 0;
    }
    dt /= tmp;
    p1 /= tmp;
    p2 /= tmp;
    long long ans = (dt * inverseMod(p1, p2)) % p2;
    while (ans * p1 < dt) ans += p2;
    //BUG(ans);
    cout << (((p1 * ans)) * tmp) + t1;
}