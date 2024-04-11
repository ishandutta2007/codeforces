#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int a, b, x;
    long long int soucin;
    soucin=1;
    cin >> a >> b;

    x=min(a, b);

    for(int i=2; i<=x; i++){
        soucin*=i;
    }

    cout << soucin;

}