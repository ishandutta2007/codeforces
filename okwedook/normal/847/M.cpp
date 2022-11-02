#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,i,a[200],d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0; i<n; i++){
        cin >> a[i];
    }
    d = a[1] - a[0];
    for(i=1; i<n; i++){
        if(a[i] - a[i - 1] != d)
            break;
    }
    if(i == n) cout << a[n - 1] + d;
    else cout << a[n - 1];
    return 0;
}