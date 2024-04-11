#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool pa;
    int sum, ma, left, right;
    cin >> n;

    long long a[n];
    bool par[n];
    int num[n];
    fill(num, num + n, 0);
    fill(par, par + n, 0);

    for(int i = 0; i<n; i++){
        cin >> a[i];
        for(int j = 0; j<62; j++){
            if(a[i] % 2){
                par[i]^=1;
                num[i]++;
            }
            a[i]/=2;
        }
    }

    bool pre[n + 1];
    pre[0] = 0;
    for(int i = 1; i<n + 1; i++){
        pre[i] = pre[i - 1] ^ par[i - 1];
    }

    int odd, even;
    long long ans = 0;
    odd = 0;
    even = 0;

    for(int i = 0; i<n + 1; i++){
        if(pre[i] == 0){
            ans += even;
            even++;
        }

        else{
            ans += odd;
            odd++;
        }
    }

    for(int i = 0; i<n; i++){
        pa = par[i];
        ma = num[i];
        sum = 0;
        left = -1;
        for(int j = i - 1; j>=0; j--){
            pa = pa ^ par[j];
            sum = sum + num[j];

            if(sum >= ma){
                left = j;
                break;
            }
        }

        for(int j = left + 1; j<=i; j++){
            sum = num[j];
            pa = par[j];
            if(j == i && pa % 2 == 0) ans--;

            for(int k = j + 1; k<n; k++){
                sum += num[k];
                pa ^= par[k];

                if(k >= i && sum < 2*ma && pa % 2 == 0) ans--;
                else if(sum >= 2*ma) break;
            }
        }
    }

    cout << ans;

}