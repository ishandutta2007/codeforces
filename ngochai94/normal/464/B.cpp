#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

struct Point {
    long long x, y, z;
};

Point p[8];
vector<long long> v;
int cnt[3];
long long side;

long long dis(Point p1, Point p2){
    return sqr(p1.x - p2.x) + sqr(p1.y - p2.y) + sqr(p1.z - p2.z);
}

bool chk() {
    v.clear();
    side = (1ll << 55);
    REP (i, 8) FOR (j, i + 1, 7) {
        v.pb(dis(p[i], p[j]));
        side = min(side, v.back());
    }
    cnt[0] = cnt[1] = cnt[2] = 0;
    if (!side) return false;
    for (long long l: v) {
        if (l % side || l / side > 3) return false;
        cnt[l / side - 1]++;
    }
    return cnt[0] == 12 && cnt[1] == 12 && cnt[2] == 4;
}

bool solve(int a) {
    // if (a < 5) BUG(a);
    // BUG(a);
    if (a == 8) {
        return chk();
    }
    if (solve(a + 1)) return true;
    swap(p[a].y, p[a].z);
    if (solve(a + 1)) return true;
    swap(p[a].x, p[a].y);
    if (solve(a + 1)) return true;
    swap(p[a].y, p[a].z);
    if (solve(a + 1)) return true;
    swap(p[a].x, p[a].y);
    if (solve(a + 1)) return true;
    swap(p[a].y, p[a].z);
    return solve(a + 1);
}

int main(){
    ios::sync_with_stdio(0);
    REP (i, 8) cin >> p[i].x >> p[i].y >> p[i].z;
    if (solve(1)) {
        cout << "YES" << endl;
        REP (i, 8) cout << p[i].x << ' ' << p[i].y << ' ' << p[i].z << endl;
    } else cout << "NO";
}