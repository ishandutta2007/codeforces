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

string s, cur;
int cnt[26];
char grid[2][13];

void construct(int x)
{
    int row = 0, col = x;
    REP (i, 26)
    {
        grid[row][col] = cur[i];
        if (!row && col == 12) row = 1;
        else if (row == 1 && !col) row = 0;
        else if (row) col--;
        else col++;
    }
}

bool ok(int x)
{
    int row = 0;
    int col = x;
    int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    FOR (i, 1, 26)
    {
        //cout << row << col << endl;
        bool flag = false;
        REP (dd, 8)
        {
            int newr = row + dr[dd];
            int newc = col + dc[dd];
            if (newr >= 0 && newc >= 0 && newr < 2 && newc < 13 )
            {
                //BUG(dd);
                if (grid[newr][newc] == s[i])
                {
                    row = newr;
                    col = newc;
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) return false;
    }
    return true;
}

void f()
{
    REP (i, 2)
    {
        REP (j, 13) cout << grid[i][j];
        cout << endl;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> s;
    REP (i, 26) if (s[i] == s[i + 1])
    {
        cout << "Impossible";
        return 0;
    }
    cur = "";
    for (char c: s)
    {
        if (!cnt[c - 'A'])
        {
            cnt[c - 'A'] = 1;
            cur += c;
        }
    }
    //construct(12);f();cout << ok(12);return 0;
    REP (i, 13)
    {
        //BUG(i);
        construct(i);
        if (ok(i))
        {
            f();
            return 0;
        }
    }

    cout << "Impossible";
}