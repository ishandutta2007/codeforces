#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long int n;
    long double a, vx, vy, ux, uy, wx, wy;
    a=999999999;
    cin >> n;
    int x[n+2];
    int y[n+2];

    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    x[n]=x[0];
    x[n+1]=x[1];
    y[n]=y[0];
    y[n+1]=y[1];

    for(int i=0; i<n; i++){
        ux=x[i]-x[i+1];
        vx=x[i+2]-x[i+1];
        uy=y[i]-y[i+1];
        vy=y[i+2]-y[i+1];
        wx=x[i+2]-x[i];
        wy=y[i+2]-y[i];

        a=min(a, abs(ux*vy-uy*vx)/(2*sqrt(wx*wx+wy*wy)));
    }

    cout << setprecision(20) << a;
}