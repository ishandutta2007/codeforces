#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,c0=0,c5=0,t;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t;
        if (t == 0) c0++;
        else if (t == 5) c5++;
    }
    if (c5 / 9 > 0 && c0 > 0){
        for(int i=0; i<c5/9*9; i++) cout << "5";
        for(int i=0; i<c0; i++) cout << "0";
    }
    else if (c0 > 0) cout << "0";
    else cout << "-1";
    cout << endl;
    return 0;
}