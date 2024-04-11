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

long long n, val;

long long expo(long long a, long long b) {
    long long ret = 1;
    FORD (i, 60, 0) {
        ret *= ret;
        ret %= mod;
        if ((1ll << i) & b) {
            ret *= a;
            ret %= mod;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    long long nume = 2, deno = 0;
    cin >> n;
    bool flag = false;
    while (n--) {
        cin >> val;
        nume = expo(nume, val);
        if (val % 2 == 0) flag = true;
    }
    deno = (nume * expo(2, mod - 2)) % mod;
    nume = (nume * expo(6, mod - 2)) % mod;
    if (flag) nume  = (nume + expo(3, mod - 2)) % mod;
    else nume = (nume + mod - expo(3, mod - 2)) % mod;
    cout << nume << '/' << deno;
}