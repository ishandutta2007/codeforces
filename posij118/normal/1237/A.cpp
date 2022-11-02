#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    int cnt = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(a[i] % 2) cnt++;
    }

    int cur = 0;
    for(int i = 0; i<n; i++){
        if(a[i] % 2 && cur < cnt/2){
            cout << (a[i] + 20000) / 2 - 10000 << endl;
            cur++;
        }

        else if(a[i] % 2){
             cout << (a[i] + 20000) / 2 - 9999 << endl;
             cur++;
        }

        else cout << a[i] / 2 << endl;
    }

}