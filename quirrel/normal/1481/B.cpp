#include<bits/stdc++.h>
using namespace std;
int h[100009];
main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> h[i];
        }
        int ans;
        while(k--){
            int i;
            for(i = 1; i < n; i++){
                if(h[i] < h[i+1]) break;
            }
            ans = i; h[i]++;
            if(i == n) break;
        }
        if(ans == n) cout << -1 << endl;
        else cout << ans << endl;
    }
}