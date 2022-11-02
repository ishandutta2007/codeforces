#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

    int n;
    cin >> n;
    int a[n], b[n], c[n];
    int f, l;
    f = 0;
    l = 0;

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    for(int i = 0; i<n; i++){
        cin >> b[i];
    }

    for(int i = 0; i<n; i++){
        cin >> c[i];
    }

    for(int i = 0; i<n; i++){
        if(a[i] != f && a[i] != l){
            cout << a[i] << " ";
            if(i == 0) f = a[i];
            l = a[i];
        }

        else if(b[i] != f && b[i] != l){
            cout << b[i] << " ";
            if(i == 0) f = b[i];
            l = b[i];
        }

        else if(c[i] != f && c[i] != l){
            cout << c[i] << " ";
            if(i == 0) f = c[i];
            l = c[i];
        }
    }

    cout << endl;

    }

}