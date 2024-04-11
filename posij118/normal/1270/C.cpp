#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        long long a[n], sum, xo;
        sum = 0;
        xo = 0;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            sum += a[i];
            xo ^= a[i];
        }

        cout << 2 << endl;
        cout << xo << " " << sum + xo << endl;
    }



}