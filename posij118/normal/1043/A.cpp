#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ma, sua, sub;
    ma = 0;
    cin >> n;

    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
        ma = max(a[i], ma);
    }

    for(int k = ma; k<1000; k++){
        sua = 0;
        sub = 0;

        for(int i = 0; i<n; i++){
            sua += (k - a[i]);
            sub += a[i];
        }

        if(sua > sub){
            cout << k;
            return 0;
        }
    }

}