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
#define oo
#define maxn 100010

using namespace std;

int st[maxn], top = 0;
int s, ans = 0, n;

int main()
{
    //freopen(filein, "r", stdin);
    //freopen(fileout, "w", stdout);
    Ri(n);
    FOR(i, 1, n)
    {
        Ri(s);
        while(top && st[top] < s) ans = max(ans, s ^ st[top--]);
        if(top) ans = max(ans,s ^ st[top]);
        st[++top] = s;
    }
    cout << ans;
    return 0;
}