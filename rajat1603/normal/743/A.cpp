#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int l , r;
char str[N];
int main(){
    cin >> n >> l >> r;
    cin >> (str + 1);
    if(str[l] == str[r]){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
    }
}