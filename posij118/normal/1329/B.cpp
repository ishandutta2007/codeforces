#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int d, m;
        cin >> d >> m;

        int p;
        for(int i = 30; i>=0; i--){
            if((1 << i) & d){
                p = i;
                break;
            }
        }

        long long ans = 1;
        for(int i = 0; i<=p - 1; i++){
            ans *= ((1 << i) + 1);
            ans %= m;
        }

        ans *= ((d - (1 << p)) + 2);
        ans += m - 1;
        ans %= m;

        cout << ans << endl;
    }

}