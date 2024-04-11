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
#define LIMIT

using namespace std;

int n, k;

int main()
{
    //filein, fileout;
    Ri(n), Ri(k);
    if(k > n)
    {
        cout << -1;
        return 0;
    }
    if(k == 1)
    {
        cout << (n == 1? "a" : "-1");
        return 0;
    }
    FOR(i, 1, n - k + 2) cout << (i % 2 ? "a" : "b");
    FOR(i, 3, k) cout << char(i + 96);
    return 0;
}