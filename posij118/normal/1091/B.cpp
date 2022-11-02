#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int x[n], y[n], a[n], b[n];
    long long sumx, sumy;
    sumx = 0;
    sumy = 0;
    for(int i = 0; i<n; i++){
        cin >> x[i] >> y[i];
        sumx += x[i];
        sumy += y[i];
    }

    for(int i = 0; i<n; i++){
        cin >> a[i] >> b[i];
        sumx += a[i];
        sumy += b[i];
    }

    cout << sumx / n << " " << sumy / n;



}