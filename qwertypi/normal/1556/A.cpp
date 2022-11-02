#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int I = 0; I < t; I++){
        int a, b;
        cin >> a >> b;
        if(a == b && b == 0){
            cout << 0<< endl;
        }
        else if(a + b == 0 | a == b){
            cout << 1 << endl;
        }else cout << ((a+ b) % 2 ? -1 : 2) << endl;
    }
}