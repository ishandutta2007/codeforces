#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    if(l>y*k || r<x*k || ((l/k)==(r/k) && l%k!=0)) cout << "NO";
    else cout << "YES";

}