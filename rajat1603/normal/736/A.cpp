#include "bits/stdc++.h"
using namespace std;
long long n;
int ans;
long long a , b , c;
int main(){
    cin >> n;
    ans = 0;
    a = 1;
    b = 2;
    while(1){
        c = a + b;
        if(c > n){
            break;
        }
        a = b;
        b = c;
        ++ans;
    }
    printf("%d\n" , ans + 1);
}