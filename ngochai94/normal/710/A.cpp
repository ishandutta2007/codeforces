#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

string s;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> s;
    if (s == "a1" || s == "a8" || s == "h1" || s == "h8")
    {
        cout << 3;return 0;
    }
    if (s[0] == 'a' || s[0] == 'h' || s[1] == '1' || s[1] == '8')
    {
        cout << 5;return 0;
    }
    cout << 8;
}