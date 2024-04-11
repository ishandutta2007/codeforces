#include "bits/stdc++.h"
using namespace std;
long long a , b;
long long temp1 , temp2;
double ans = -1;
int main(){
    cin >> a >> b;
    temp1 = a + b;
    temp2 = temp1 / b;
    temp2 -= (temp2 & 1);
    if(temp2){
       ans = 1.0 * temp1 / (1.0 * temp2);
    }
    temp1 = a - b;
    temp2 = temp1 / b;
    temp2 -= (temp2 & 1);
    if(temp2){
        double temp3 = 1.0 * temp1 / (1.0 * temp2);
        if(ans < 0 || (temp3 <= ans)){
            ans = temp3;
        }
    }
    if(ans < 0.5){
        cout << "-1";
    }
    else
        printf("%.9lf\n" , ans);
}