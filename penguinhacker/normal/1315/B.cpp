#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, p, dp[100000];
        string station;
        cin >> a >> b >> p >> station;
        dp[station.size()-1] = p;
        if (station[station.size()-2] == 'A') dp[station.size()-2] = p-a;
        else dp[station.size()-2] = p-b; 
        if (dp[station.size()-2] < 0) cout << station.size() << '\n';
        else {
            char type = station[station.size()-2];
            bool check = false;
            for (int i=station.size()-3; i>=0; --i) {
                if (station[i] != type) {
                    if (station[i] == 'A') dp[i] = dp[i+1] - a;
                    else dp[i] = dp[i+1] - b;
                    type = station[i];
                }
                else dp[i] = dp[i+1];
                if (dp[i] < 0) {
                    cout << i+2 << '\n';
                    check = true;
                    break;
                }
            }
            if (!check && dp[0] >= 0) cout << 1 << '\n';
        }
        
    }
    return 0;
}