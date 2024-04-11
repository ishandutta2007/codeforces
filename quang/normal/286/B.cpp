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
#define EXTREMELY
#define LIMIT 1000010

using namespace std;

int n;
int a[LIMIT * 3];

int main()
{
    //filein, fileout;
    Ri(n);
    FOR(i, 1, n) a[i] = i;
    FOR(i, 2, n)
    {
        int tr = 0;
        for(int j = 1; j <= n; j += i) swap(a[j + i - 2], tr);
        a[n + i - 1] = tr;
    }
    FOR(i, 1, n) cout << a[i + n - 1] << " ";
    return 0;
}