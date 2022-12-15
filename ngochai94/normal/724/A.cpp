#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,a-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

string s, ss;
int x, y;

int day2int(string x)
{
    if (x == "monday") return 0;
    if (x == "tuesday") return 1;
    if (x == "wednesday") return 2;
    if (x == "thursday") return 3;
    if (x == "friday") return 4;
    if (x == "saturday") return 5;
    if (x == "sunday") return 6;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> s >> ss;
    x = day2int(s);
    y = day2int(ss);
    if (x == y || (x + 2) % 7 == y || (x + 3) % 7 == y) cout << "YES";
    else cout << "NO";
}