#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m;
    int aa=0;
    int bb=0;
    x=0;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int b[m];
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    for(int i=0; i<n; i++){
        aa = aa ^ a[i];
    }

    for(int i=0; i<m; i++){
        bb = bb ^ b[i];
    }

    if(aa != bb){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;

    for(int i=0; i<n-1; i++){
        x = x ^ a[i];
    }

    x = x ^ b[m-1];

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            cout << "0 ";
        }

        cout << a[i] << endl;
    }

    for(int i=0; i<m-1; i++){
        cout << b[i] << " ";
    }

    cout << x;

}