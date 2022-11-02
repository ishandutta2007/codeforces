#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];
    long long pa[n+1];
    long long b[n];
    long long pb[n+1];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    pa[0]=0;
    pb[0]=0;
    for(int i=0; i<n; i++){
        pa[i+1] = pa[i] + a[i];
        pb[i+1] = pb[i] + b[i];
    }

    long long d, h, ma;
    d = 0;
    h = 0;
    ma = 0;
    for(int i=0; i<n; i++){
        h+=i * a[i];
    }
    for(int i=n-1; i>=0; i--){
        h+=(2*n - 1 - i)* b[i];
    }

    for(int i=0; i<n; i++){
        d+=(i+1) * b[i];
    }

    for(int i=n-1; i>0; i--){
        d+=(2*n-i)* a[i];
    }
    ma = max(d, h);
    for(int i = 1; i<n-1; i++){
        if(i % 2 == 1){
            h+=(2*i-1)* b[i-1];
            h+=(2*i)*b[i];
            h-=(2*n-1)*b[i-1];
            h-=(2*n-2)*b[i];
            h+=2*(pa[n] - pa[i]);
            h+=2*(pb[n] - pb[i+1]);
            ma = max(ma, h);
        }

        else{
            d+=(2*i-1)* a[i-1];
            d+=(2*i)*a[i];
            d-=(2*n-1)*a[i-1];
            d-=(2*n-2)*a[i];
            d+=2*(pb[n] - pb[i]);
            d+=2*(pa[n] - pa[i+1]);
            ma = max(ma, d);
        }
    }
    cout << ma;
}