#include "bits/stdc++.h"
using namespace std;
int n , m;
int main(){
    cin >> n >> m;
    if(n - m > m - 1 && m + 1 <= n){
        cout << m + 1;
    }
    else if(n - m <= m - 1 && m > 1){
        cout << m - 1;
    }
    else{
        cout << m;
    }
}