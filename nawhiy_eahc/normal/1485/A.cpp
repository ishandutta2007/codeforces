#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int ans = 1e9;
        for(int i=0;i<=100;i++){
            int tempa = a, tempb = b + i;
            if(tempb == 1) continue;
            int cnt = i;
            while(tempa){
                tempa /= tempb;
                cnt++;
            }

            ans = min(ans, cnt);
        }

        cout << ans << "\n";
    }
}