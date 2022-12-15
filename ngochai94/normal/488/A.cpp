#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

int n, lis[100005], pre[100005], ans, aft[100005];

bool check(int y) {
    if (y < 0) y = -y;
    while (y) {
        if (y % 10 == 8) return true;
        y /= 10;
    }
    return false;
}

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    long long x;
    cin >> x;
    FOR (i, 1, 20) if (check(x + i)) {
        cout << i;
        return 0;
    }
}