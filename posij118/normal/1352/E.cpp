#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a[n], b[n + 1];

        for(int i = 0; i<n; i++){
            cin >> a[i];
            b[i + 1] = 0;
        }

        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<=n; j++){
                sum += a[j];
                if(j != i && sum <= n){
                    b[sum] = 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            if(b[a[i]]) ans++;
        }

        cout << ans << endl;
    }

}