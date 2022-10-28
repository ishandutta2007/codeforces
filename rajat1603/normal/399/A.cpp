#include "bits/stdc++.h"
using namespace std;
int n , p , k;
int l , r;
int main(){
    cin >> n >> p >> k;
    l = max(1 , p - k);
    r = min(n , p + k);
    if(l > 1){
        cout << "<< ";
    }
    for(int i = l ; i < p ; ++i){
        cout << i << " ";
    }
    cout << "(" << p << ") ";
    for(int i = p + 1 ; i <= r ; ++i){
        cout << i << " ";
    }
    if(r < n){
        cout << ">>";
    }
}