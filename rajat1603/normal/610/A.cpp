#include "bits/stdc++.h"
using namespace std;
int n;
int main(){
    cin >> n;
    if(n & 1){
        printf("0\n");
        return 0;
    }
    cout << ((n - 1) >> 2);
}