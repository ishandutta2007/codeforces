#include "bits/stdc++.h"
using namespace std;
int a , b , c;
int x , y , z;
int extra;
int main(){
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    extra = max(0 , a - x >> 1) + max(0 , b - y >> 1) + max(0 , c - z >> 1);
    while(a < x){
        ++a;
        --extra;
    }
    while(b < y){
        ++b;
        --extra;
    }
    while(c < z){
        ++c;
        --extra;
    }
    if(extra >= 0){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}