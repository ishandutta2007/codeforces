#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int INF = 1000000000;

int n, p, s;
pair<pair<int, int>, int> student[3333];

int dp[3333][3333];
int f(int x, int y) {
    if (y > s) return -INF;
    if (x == n) return 0;
    if (~dp[x][y]) return dp[x][y];
    
    int ret = f(x+1, y+1) + student[x].fi.se;
    ret = max(ret, f(x+1, y) + (x - y + 1 <= p ? student[x].fi.fi : 0));
    return dp[x][y] = ret;
}

int main() {
    scanf("%d %d %d", &n, &p, &s);
    
    for (int i=0; i<n; i++) {
        scanf("%d", &student[i].fi.fi);
        student[i].second = i;
    }
    
    for (int i=0; i<n; i++) {
        scanf("%d", &student[i].fi.se);
    }
    
    sort(student, student + n, greater<pair<pair<int, int>, int> >());
    
    memset(dp, -1, sizeof dp);
    printf("%d\n", f(0, 0));
    int x = 0;
    int y = 0;
    vector<int> ans1, ans2;
    for(; x < n; x++) {
        if (f(x+1, y+1) + student[x].fi.se > f(x+1, y) + (x - y + 1 <= p ? student[x].fi.fi : 0)) {
            ans2.push_back(student[x].second);
            y++;
        } else {
            ans1.push_back(student[x].second);
        }
    }
    
    for (int i=0; i<p; i++) printf("%d ", ans1[i] + 1); printf("\n");
    for (int i=0; i<s; i++) printf("%d ", ans2[i] + 1); printf("\n");
    return 0;
}