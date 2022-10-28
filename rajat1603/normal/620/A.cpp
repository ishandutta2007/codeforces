#include "bits/stdc++.h"
using namespace std;
int a , b;
int c , d;
int main(){
    cin >> a >> b;
    cin >> c >> d;
    cout << max(abs(a - c) , abs(b - d));
}