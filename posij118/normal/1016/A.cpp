#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, x, y, sum;
    sum = 0;
    cin >> n >> m;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> x;
        cout << (x+sum) / m - sum / m << " ";
        sum+=x;
    }



}