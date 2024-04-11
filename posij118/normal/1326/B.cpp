#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int b[n], a[n], ma;
    ma = 0;
    for(int i = 0; i<n; i++){
        cin >> b[i];
        a[i] = ma + b[i];
        ma = max(ma, a[i]);
    }

    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }

}