#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    bool pos = 0;
    bool neg = 0;
    long long x[n], y[n];
    for(int i = 0; i<n; i++){
        cin >> x[i] >> y[i];
        if(y[i] > 0) pos = 1;
        else if(y[i] < 0) neg = 1;
    }

    if(pos & neg){
        cout << -1;
        return 0;
    }

    if(neg){
        for(int i = 0; i<n; i++){
            y[i] = -y[i];
        }
    }

    long double d, h, leftmax, rightmax, mid;
    d = (-1)*1e8;
    h = 1*1e8;

    for(int i = 0; i<60; i++){
        mid = (d + h)/2;

        leftmax = 0;
        rightmax = 0;

        for(int j = 0; j<n; j++){
            if(x[j] < mid){
                leftmax = max(leftmax, ((mid - x[j])*(mid - x[j]) + y[j]*y[j]) / (2*y[j]));
            }

            else{
                rightmax = max(rightmax, ((mid - x[j])*(mid - x[j]) + y[j]*y[j]) / (2*y[j]));
            }
        }

        if(leftmax > rightmax) h = mid;
        else d = mid;

        if(i == 59) cout << setprecision(10) << max(leftmax, rightmax);

    }
}