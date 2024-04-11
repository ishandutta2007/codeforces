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
#define LIMIT 100010

using namespace std;

int n;
int a[LIMIT];

int main()
{
    //filein;
    //fileout;
    Ri(n);
    if(n % 4 == 0 || n % 4 == 1)
    {
        int l = 1, r = n;
        while(r > l)
        {
            a[l] = l + 1;
            a[l + 1] = r;
            a[r] = r - 1;
            a[r - 1] = l;
            l += 2, r -= 2;
        }
        if(n % 4 == 1) a[l] = n / 2 + 1;
        FOR(i, 1, n) cout << a[i] << " ";
    }
    else cout << -1;
    return 0;
}