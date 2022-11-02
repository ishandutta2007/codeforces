#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ma;
    cin >> n;

    int a[n];
    ma = -1;

    for(int i = 0; i<n; i++){
        cin >> a[i];

        if(a[i] > ma + 1){
            cout << i + 1;
            return 0;
        }

        ma = max(ma, a[i]);
    }

    cout << -1;

}