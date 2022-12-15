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

long long n;
vector<long long> v;

int extgcd(int a, int b, int &x, int &y) {
    int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

int inverseMod(int a, int m) {
  int x, y;
  extgcd(a, m, x, y);
  return (x + m) % m;
}

void prime(int x)
{
    if (x % 2 == 0) v.pb(2);
    while (x % 2 == 0) x /= 2;
    for (int i = 3; i * i <= x; i += 2) if (x % i  == 0)
    {
        while (x % i == 0)
        {
            x /= i;
        }
        v.pb(i);
    }
    if (x != 1) v.pb(x);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    if (n == 1)
    {
        cout << "YES" << endl << 1;
        return 0;
    }
    prime(n);
    if (v.size() > 1)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    long long cur = 1;
    long long last = 1;
    long long x = v[0];
    while (cur < n)
    {
        if (cur != 1) cout << (inverseMod(last, n) * x) % n << endl;
        else cout << 1 << endl;
        last = 1;
        for (long long i = 2; i * cur < n; i++) if (i % x)
        {
            cout << (inverseMod(last, n) * i) % n << endl;
            last = i;
        }
        cur *= x;
    }
    cout << n << endl;
}