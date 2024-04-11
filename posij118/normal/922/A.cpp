#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    if(x+2<=y || y==0  || (y==1 && x>0)) cout << "No";





    else if(y%2==1){
        if(x%2==0) cout << "Yes";
        else cout << "No";
    }

    else{
        if(x%2==1) cout << "Yes";
        else cout << "No";
    }

}