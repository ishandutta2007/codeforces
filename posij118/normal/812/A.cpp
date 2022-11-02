#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    bool a[4][4];
    int skap=0;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<4; i++){
        if(a[i][3]==1 && (a[i][0]==1 || a[i][1]==1 || a[i][2]==1 ||  a[(i+1)%4][0]==1 || a[(i+2)%4][1]==1 || a[(i+3)%4][2]==1)) skap=1;
    }

    if(skap==1) cout << "YES";
    else cout << "NO";

}