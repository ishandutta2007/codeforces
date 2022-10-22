#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll p[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        for(int i=1;i<n;i++){
            p[i] += p[i-1];
        }

        ll ans = 0;

        for(int i=1;i<n;i++){
            ll temp = 0;
            temp = (100 * (p[i] - p[i-1]) + k -1 )/k - p[i-1];
            ans = max(ans, temp);
        }
        cout << ans << "\n";
    }
}