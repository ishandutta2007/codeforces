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
#define MAXN 300005

int n, lis[3 * MAXN], mins[20][3 * MAXN], gcd[20][3 * MAXN], below[9 * MAXN];

int GCD(int x, int y) {
    // cout << x << ' ' << y << endl;
    if (!x || !y) return max(x, y);
    return __gcd(x, y);
}

void construct() {
    int range = 1;
    FOR (i, 1, n) mins[0][i] = gcd[0][i] = lis[i];
    below[1] = 0;
    FOR (i, 1, 19) {
        range *= 2;
        FOR (j, range, range * 2 - 1) below[j] = i;
        FOR (j, 1, n - range + 1) {
            mins[i][j] = min(mins[i - 1][j], mins[i - 1][j + range / 2]);
            gcd[i][j] = GCD(gcd[i - 1][j], gcd[i - 1][j + range / 2]);
            // cout << i << ' '<< j << ' ' << mins[i][j] << endl;
        }
    }
}

int getMin(int x, int ll, int rr) {
    x = below[rr - ll + 1];
    // cout << x << endl;
    return min(mins[x][ll], mins[x][rr - (1 << x) + 1]);
}

int getGcd(int x, int ll, int rr) {
    x = below[rr - ll + 1];
    return GCD(gcd[x][ll], gcd[x][rr - (1 << x) + 1]);
}

vector<int> v;

bool check(int range) {
    FOR (i, 1, n - range) {
        if (getGcd(1, i, i + range) == getMin(1, i, i + range)) return true;
    }
    return false;
}

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    // ios::sync_with_stdio(0);
    scanf("%d", &n);
    FOR (i, 1, n) scanf("%d", &lis[i]);
    construct();
    // cout << getMin(1, 1, 3);return 0;
    int high = n, low = 0;
    while (high > low) {
        int mid = (high + low) / 2;
        if (check(mid)) low = mid + 1;
        else high = mid;
    }
    low--;
    FOR (i, 1, n - low) {
        if (getMin(1, i, i + low) == getGcd(1, i, i + low)) v.pb(i);
    }
    cout << v.size() << ' ' << low << endl;
    for (int i: v) cout << i << ' ';

}