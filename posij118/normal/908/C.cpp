#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, r;
    long double dm, hm, mid;
    cin >> n >> r;
    int x[n];
    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    long double y[n];

    for(int i=0; i<n; i++){
        y[i]=r;
        for(int j=0; j<i; j++){
            dm=y[j];
            hm=9595698.9;
            if(abs(x[i]-x[j])>2*r) continue;
            for(int k=0; k<52; k++){
                mid=(dm+hm)/2;
                if(((y[j]-mid)*(y[j]-mid)+(x[i]-x[j])*(x[i]-x[j]))>(4*r*r)) hm=mid;
                else if (((y[j]-mid)*(y[j]-mid)+(x[i]-x[j])*(x[i]-x[j]))<(4*r*r)) dm=mid;
            }

            y[i]=max(y[i], mid);
        }
    }

    for(int i=0; i<n; i++){
        cout << setprecision(10) << y[i] << " ";
    }

}