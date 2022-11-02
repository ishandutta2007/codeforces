#include <bits/stdc++.h>
using namespace std;

int main(){
    int b, k;
    cin >> b >> k;

    int a[k], sum;
    for(int i = 0; i<k; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(b % 2){
        if(sum % 2) cout << "odd";
        else cout << "even";
    }

    else if (a[k - 1] % 2) cout << "odd";
    else cout << "even";

}