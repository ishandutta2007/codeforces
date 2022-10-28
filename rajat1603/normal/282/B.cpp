#include "bits/stdc++.h"
using namespace std;
string ans;
int n;
int a , b;
int sum = 0;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a , &b);
        if(sum + a <= 500){
            sum += a;
            ans += 'A';
        }
        else{
            sum -= b;
            ans += 'G';
        }
    }
    if(sum >= -500){
        cout << ans;
    }
    else{
        cout << -1;
    }
}