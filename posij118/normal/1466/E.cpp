#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9 + 7;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        long long x[n];
        long long two[60];
        long long ans = 0;
        two[0] = 1;
        for(int i = 1; i<60; i++){
            two[i] = (two[i - 1] * 2) % M;
        }
        int cnt[60];
        fill(cnt, cnt + 60, 0);

        for(int i = 0; i<n; i++){
            cin >> x[i];
            for(int j = 0; j<60; j++){
                if((1LL << j) & x[i]) cnt[j]++;
            }
        }

        for(int j = 0; j<n; j++){
            long long l = 0;
            long long r = 0;

            for(int k = 0; k<60; k++){
                if(x[j] & (1LL << k)){
                    l += (cnt[k] * two[k]);
                    l %= M;
                    r += (n*two[k]);
                    r %= M;
                }

                else{
                    r += (cnt[k] * two[k]);
                    r %= M;
                }
            }

            ans += l*r;
            ans %= M;
        }

        cout << ans << endl;

    }

}