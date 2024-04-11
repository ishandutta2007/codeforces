#include <bits/stdc++.h>

using namespace std;

struct celebrity{
    int t, x, y;
    celebrity() : celebrity(0, 0, 0) {}
    celebrity(int _t, int _x, int _y) : t(_t), x(_x), y(_y) {}

    bool poss (const celebrity &O){
        return abs(x - O.x) + abs(y - O.y) <= abs(t - O.t);
    }
};
celebrity C[100002];
int dp[100002];
int dp_max[100002];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int r, n; cin >> r >> n;
    C[0] = celebrity(0, 1, 1);
    for(int i=1;i<=n;i++){
        dp[i] = -1000000000;
    }
    for(int i=1;i<=n;i++){
        int _t, _x, _y;
        cin >> _t >> _x >> _y;
        C[i] = celebrity(_t, _x, _y);
        for(int j = max(0, i - 1000);j<i;j++){
            if(C[i].poss(C[j])) dp[i] = max(dp[i], dp[j] + 1);
        }
        if(i > 1000) dp[i] = max(dp[i], dp_max[i - 1001] + 1);
        dp_max[i] = max(dp_max[i-1], dp[i]);
    }

    cout << dp_max[n];
}