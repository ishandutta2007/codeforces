#include "bits/stdc++.h"
using namespace std;
int a , b;
int main(){
    cin >> a >> b;
    if(abs(a - b) <= 1 && max(a , b) > 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}