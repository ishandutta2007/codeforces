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

long long a1, b1, a2, b2, l, r;

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

long long solve(long long a1, long long a2, long long b2, long long x)
{
    if (x < 0) return 0;
    long long tmp = __gcd(a1, a2);
    if (b2 % tmp) return 0;
    b2 /= tmp;
    a1 /= tmp;
    a2 /= tmp;
    x /= tmp;
    if (a2 == 1) return 1 + x / a1;
    long long k = (b2 * inverseMod(a1, a2)) % a2;
    k *= a1;
    x -= k;
    if (x < 0) return 0;
    return 1 + x / (a1 * a2);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
    if (b2 < b1)
    {
        swap(b1, b2);
        swap(a1, a2);
    }
    b2 -= b1;
    l -= b1;
    r -= b1;
    if (r < b2)
    {
        cout << 0;
        return 0;
    }
    l = max(l, 0ll);
    //BUG(b2);
    //cout << solve(a1, a2, b2, 16) - solve(a1, a2, b2, 10); return 0;
    if (l - 1 < b2) cout << solve(a1, a2, b2, r) - solve(a1, a2, b2, b2 - 1);
    else cout << solve(a1, a2, b2, r) - solve(a1, a2, b2, l - 1);
}