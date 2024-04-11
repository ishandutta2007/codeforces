#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

long long n, l, r, a[100005], b[100005];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n)
    {
        cin >> a[i] >> b[i];
        l += a[i];
        r += b[i];
    }
    long long ans = abs(l - r);
    int col = 0;
    REP (i, n)
    {
        l += b[i] - a[i];
        r += a[i] - b[i];
        if (ans < abs(l - r))
        {
            ans = abs(l - r);
            col = i + 1;
        }
        l += a[i] - b[i];
        r += b[i] - a[i];
    }
    cout << col;
}