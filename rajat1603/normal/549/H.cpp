#include "bits/stdc++.h"
using namespace std;
int a , b , c , d;
double l = 0.0 , r = 1e9;
double mid;
bool check(){
    double mn = 1e18;
    double mx = -mn;
    for(int i = -1 ; i < 2 ; i += 2){
        for(int j = -1 ; j < 2 ; j += 2){
            for(int k = -1 ; k < 2 ; k += 2){
                for(int l = -1 ; l < 2 ; l += 2){
                    double x , y , z , whatcomesafterz;
                    x = a + mid * i;
                    y = b + mid * j;
                    z = c + mid * k;
                    whatcomesafterz = d + mid * l;
                    mn = min(mn , x * whatcomesafterz - y * z);
                    mx = max(mx , x * whatcomesafterz - y * z);
                }
            }
        }
    }
    return mn <= 0 && mx >= 0 ;
}
int main(){
    cin >> a >> b >> c >> d;
    for(int i = 0 ; i < 2048 ; ++i){
        mid = (l + r) / 2.0;
        if(check()){
            r = mid;
        }
        else{
            l = mid + 1e-15;
        }
    }
    printf("%.9lf" , r);
}