#include "bits/stdc++.h"
using namespace std;
int t , n;
int main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    cin >> t;
    while(t--){
        cin >> n;
        cout << (1 ^ n & 1) << endl;
    }
}