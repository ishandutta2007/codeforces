#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define inf (1 << 30)
using namespace std;

bool test(int t1, int t2){
    int gcd = __gcd(t1, t2);
    t1 /= gcd;
    t2 /= gcd;
    while(t1 % 2 == 0){
        t1 /= 2;
    }
    while(t1 % 3 == 0){
        t1 /= 3;
    }
    while(t2 % 2 == 0){
        t2 /= 2;
    }
    while(t2 % 3 == 0){
        t2 /= 3;
    }
    return t1 + t2 != 2;
}

int main(){
    int n;
    cin >> n;
    int t;
    cin >> t;
    for(int i=1;i<n;i++){
        int k;
        cin >> k;
        if(test(t, k)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}