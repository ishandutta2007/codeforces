#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define X first
#define Y second
#define filein "inp.txt"
#define fileout "out.txt"
#define oo 1000000007LL
#define maxn 20

using namespace std;

ll kq;
int n;
/*bool kt[maxn], kt2[maxn];

void Try(int i)
{
    if(i > n)
    {
        kq++;
        return;
    }
    FOR(j, 1, n)
    if(!kt[j] && !kt2[(i + j - 2) % n + 1])
    {
        kt[j] = 1;
        kt2[(i + j - 2) % n + 1] = 1;
        Try(i + 1);
        kt[j] = 0;
        kt2[(i + j - 2) % n + 1] = 0;
    }
}*/

ll a[] = {1,3,15,133,2025,37851,1030367,36362925};
ll gt[maxn];

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    cin >> n;
    gt[1] = 1ll;
    if(n % 2)
    {
        ll x = a[n / 2];
        FOR(i, 2, n) x = (x * i) % oo;
        cout << x;
    }
    else cout << 0;
    return 0;
}