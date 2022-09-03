#include <cstdio>
#include <cmath>
#define min(a,b) (a < b ? a : b)
typedef long long ll;
int fa[100005][20];
int fn[100005];
int p;
void init(int m)
{
    for (int i = 2; i <= m; ++i) {
        if (!fn[i]) {
            fa[i][fn[i]++] = i;
            for (int j = i+i; j <= m; j += i)
                fa[j][fn[j]++] = i;
        }
    }
}
ll n, m;
ll sum(ll f, ll x)
{
    ll k = x/f;
    k = ((n+1)*k-(k+1)*k*f/2) % p;
    return k < 0 ? k+p : k;
}
ll calc(ll f, ll l, ll r)
{
    ll k = (sum(f,r)-sum(f,l-1)) % p;
    return k < 0 ? k+p : k;
}
int main(int argc, char const *argv[])
{
  //  freopen("in", "r", stdin);
    ll l, r, ans = 0;
    scanf("%I64d%I64d", &n, &m);
    scanf("%I64d%I64d%d", &l, &r, &p);
    init(m);
    ll lx = l; ll rx = r; ll ret = 0;
    for (ll dy = 1; dy <= min(m,r); ++dy) {

        while (lx > 1 && l*l - dy*dy <= (lx-1)*(lx-1)) --lx;
        while (r*r - dy*dy < rx*rx) --rx;
        ll s = 0;
        
        // printf("dy=%I64d %I64d<=dx<=%I64d\n", dy, lx, rx);
        if (lx <= rx && lx <= n) {
            for (int i = 0; i < (1 << fn[dy]); ++i) {
                ll f = 1;
                ll t = 1;
                for (int j = 0; j < fn[dy]; ++j) {
                    if (i & (1 <<j)) {
                        f *= fa[dy][j];
                        t *= -1;
                    }
                }
                s += t*calc(f, lx, min(rx,n));
            }
        }
        ans = (ans+s*(m+1-dy)) % p;
        ans = (ans < 0 ? ans+p : ans);
    } // dy!=0
    // adjacent points
    if (l <= 1 && r >= 1) ans = (ans*2+(n+1)*m+n*(m+1)) % p;
    else ans = (ans*2) % p;
    printf("%I64d\n", ans);
    return 0;
}