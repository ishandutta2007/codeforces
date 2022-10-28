#include "bits/stdc++.h"
using namespace std;
int a , b;
int main(){
    cin >> a >> b;
    cout << min(a , b) << " " << (max(a , b) - min(a , b)) / 2;
}