#include "bits/stdc++.h"
using namespace std;
int t;
long long a , b;
double ans;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(b == 0){
            printf("1\n");
            continue;
        }
        if(a == 0){
            printf("0.5\n");
            continue;
        }
        ans = a * b;
        if(b * 4 >= a){
            ans += a * a / 8.0;
        }
        else{
            ans += a * b;
            ans -= b * 2.0 * b;
        }
        ans /= a * b * 2.0;
        printf("%.6lf\n" , ans);
    }
}