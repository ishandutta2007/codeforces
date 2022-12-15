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

int n;
string s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    int ans = 0;
    cin >> n >> s;
    REP (i, n)
    {
        if (s[i] == '<') ans++;
        else break;
    }
    FORD (i, n-1, 0)
    {
        if (s[i] == '>') ans++;
        else break;
    }
    cout << ans;
}