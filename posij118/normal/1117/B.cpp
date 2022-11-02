#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, k;

    long long ma, ma2;
    ma = 0;
    ma2 = 0;
    cin >> n >> m >> k;

    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(a[i] > ma){
            ma2 = ma;
            ma = a[i];
        }

        else if(a[i] > ma2) ma2 = a[i];
    }

    long long ans;
    ans = (m / (k  + 1)) * (ma * k + ma2);
    m  %= (k + 1);

    ans += m * ma;
    cout << ans;

}