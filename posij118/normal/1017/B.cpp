#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

int main(){
    int n;
    long long ans;
    cin >> n;

    string a, b;
    cin >> a >> b;

    long long za, zb, zo, oo;
    za = 0;
    zb = 0;
    zo = 0;
    oo = 0;
    for(int i=0; i<n; i++){
        if(a[i] == '0') za++;
        if(b[i] == '0') zb++;
        if(a[i] == '0' && b[i] == '1') zo++;
        if(a[i] == '1' && b[i] == '1') oo++;
    }

    ans = za * (n - za) - zo * oo;
    cout << ans;

}