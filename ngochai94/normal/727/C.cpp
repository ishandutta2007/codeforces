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

int n, s, lis[5555];

int query(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int res;
    fflush(stdout);
    cin >> res;
    return res;
}

int main(){
    // ios::sync_with_stdio(0);
    cin >> n;
    int x = query(1, 2);
    int y = query(2, 3);
    int z = query(1, 3);
    lis[1] = (x + z - y) / 2;
    lis[2] = x - lis[1];
    lis[3] = z - lis[1];
    FOR (i, 4, n) {
        x = query(1, i);
        lis[i] = x - lis[1];
    }
    cout << "! ";
    FOR (i, 1, n) cout << lis[i] << ' ';
    cout << endl;
}