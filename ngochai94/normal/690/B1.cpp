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

int n;
string grid[55];

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> grid[i];
    int up = 111, left = 111, down = -1, right = -1;
    REP (i, n) REP (j, n) if (grid[i][j] == '4')
    {
        up = min(up, i);
        down = max(down, i);
        left = min(left, j);
        right = max(right, j);
    }
    if (down < 0)
    {
        cout << "No";
        return 0;
    }
    REP (i, n) REP (j, n)
    {
        if (i >= up && i <= down && j >= left && j <= right)
        {
            if (grid[i][j] != '4')
            {
                cout << "No";
                return 0;
            }
        }
        else if (i == up - 1 && j >= left && j <= right
                 || i == down + 1 && j >= left && j <= right
                 || j == left - 1 && i >= up && i <= down
                 || j == right + 1 && i >= up && i <= down)
        {
            if (grid[i][j] != '2')
            {
                cout << "No";
                return 0;
            }
        }
        else if (i == up - 1 && (j == left - 1 || j == right + 1)
                 || i == down + 1 && (j == left - 1 || j == right + 1))
        {
            if (grid[i][j] != '1')
            {
                cout << "No";
                return 0;
            }
        }
        else if (grid[i][j] != '0')
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}