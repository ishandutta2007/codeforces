#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORN(i, a, b) for(int i = a; i >= b; i--)
#define Ri(x) scanf("%d", &x)
#define Rll(x) scanf("%I64d", &x)
#define ll long long
#define make_pair mp
#define X first
#define Y second
#define push_back pb
#define filein "inp.txt"
#define fileout "out.txt"

#define oo
#define maxn 200010

using namespace std;

int n, stt;
int a[maxn] = {0};
int lan[2][maxn];
ll nho[2][maxn];

ll dfs(int diem, int dir)
{
    if(diem <= 0 || diem > n) return 0;
    if(lan[dir][diem] == stt) return -1;
    lan[dir][diem] = stt;
    if(nho[dir][diem]) return nho[dir][diem];
    ll tong = dfs(diem + a[diem] * (dir ? - 1 : 1), !dir);
    return nho[dir][diem] = tong == -1 ? -1 : tong + a[diem];
}

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    Ri(n);
    FOR(i, 2, n) Ri(a[i]);

    FOR(i, 1, n - 1)
    {
        lan[1][1] = stt = i;
        ll tong = dfs(1 + i, 1);
        printf("%I64d\n", tong == -1 ? -1 : tong + i);
    }

    return 0;
}