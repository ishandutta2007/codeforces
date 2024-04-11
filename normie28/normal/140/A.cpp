#include <iostream>
#include <cmath>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
 
double R,r,pi=atan(1)*4,n;
 
int main(){
optimizar_io
    cin>>n>>R>>r;
    if (r>R){
        cout<<"NO";
    }else if (r*2>R){
        if (n==1){
            cout<<"YES";
        }else cout<<"NO";
    }else if (r*2==R){
        if (n<3){
            cout<<"YES";
        }else cout<<"NO";
    }else if (n<pi/asin(r/(R-r)) || n-(pi/asin(r/(R-r)))<0.00000000000001){
        cout<<"YES";
    }else cout<<"NO";
}