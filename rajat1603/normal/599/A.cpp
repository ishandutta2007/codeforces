#include "bits/stdc++.h"
using namespace std;
int a , b , c;
int main(){
    cin >> a >> b >> c;
    cout << min(a + b + c , min(2 * (a + b) , min(2 * (a + c) , 2 * (b + c))));
}