#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll S[5002], S2[5002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n; ll ans = 0;
        for(int i=1;i<=n;i++){
            cin >> S[i];
            S2[i] = S[i];
        }
        S2[n+1] = 1e18;
        for(int i=1;i<=n;i++){
            int next = i+2;
            for(int j=i+2;j<=min(1LL*n, i + S[i]);j++){
                for(int k = max(next, j);k<=n+1;k++){
                    if(S2[k] > 1){
                        next = k;
                        break;
                    }
                }
                S2[next]--;
            }
            ans += max(S2[i] - 1, 0LL);
        }

        cout << ans << "\n";
    }
}