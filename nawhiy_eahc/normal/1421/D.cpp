#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        ll cost[7];
        for(int i=1;i<=6;i++){
            cin >> cost[i];
        }
        for(int i=1;i<=10;i++){
            cost[1] = min(cost[1], cost[2] + cost[6]);
            cost[6] = min(cost[6], cost[1] + cost[5]);
            for(int j=2;j<=5;j++){
                cost[j] = min(cost[j], cost[j-1] + cost[j+1]);
            }
        }

        ll ans = 0;

        if(x > 0 && y > 0){
            ans += min(x, y) * cost[1];
            if(x > y) ans += (x-y) * cost[6];
            else ans += (y-x) * cost[2];
        }
        else if(x < 0 && y < 0){
            x = -x, y = -y;
            ans += min(x, y) * cost[4];
            if(x > y) ans += (x-y) * cost[3];
            else ans += (y-x) * cost[5];
        }
        else{
            if(x > 0) ans += x * cost[6];
            else ans += -x * cost[3];
            if(y > 0) ans += y * cost[2];
            else ans += -y * cost[5];
        }

        cout << ans << "\n";
    }
}