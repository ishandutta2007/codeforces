#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,a) FOR(i,0,a-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n, m;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP (i, m) cout << '#';
    cout << endl;
    FOR (i, 2, n)
    {
        if (i & 1)
        {
            REP (i, m) cout << '#';
            cout << endl;
            continue;
        }
        if ((i / 2) & 1)
        {
            REP (j, m - 1) cout << '.';
            cout << '#' << endl;
        }
        else
        {
            cout << '#';
            REP (j, m - 1) cout << '.';
            cout << endl;
        }
    }
}