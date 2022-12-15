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

int curmin, curmax;

int t, n;

bool les(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    fflush(stdout);
    char c;
    cin >> c;
    if (c == '<') return true;
    else return false;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        curmin = curmax = 1;
        if (n % 2 == 0)
        {
            if (les(1, 2)) curmax = 2;
            else curmin = 2;
        }
        for (int i = 3 - n % 2; i + 1 <= n; i += 2)
        {
            if (les(i, i + 1))
            {
                if (les(i, curmin)) curmin = i;
                if (les(curmax, i + 1)) curmax = i + 1;
            }
            else
            {
                if (les(i + 1, curmin)) curmin = i + 1;
                if (les(curmax, i)) curmax = i;
            }
        }
        cout << "! " << curmin << ' ' << curmax << endl;
        fflush(stdout);
    }
}