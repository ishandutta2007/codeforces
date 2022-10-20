#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define X first
#define Y second
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY  1000000007ll
#define LIMIT

using namespace std;

int n, k;
ll kq = 1ll;

int main()
{
    //filein, fileout;
    Ri(n), Ri(k);
    FOR(i, 1, k - 1) kq = (kq * 1ll * k) % EXTREMELY;
    FOR(i, 1, n - k) kq = (kq * 1ll * (n - k)) % EXTREMELY;
    cout << kq;
    return 0;
}