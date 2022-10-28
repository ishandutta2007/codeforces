#include "bits/stdc++.h"
using namespace std;
string a , b;
int n;
string c , d;
int main(){
    cin >> a >> b;
    cin >> n;
    while(n--){
        cout << a << " " << b << endl;
        cin >> c >> d;
        if(c == a){
            a = d;
        }
        else{
            b = d;
        }
    }
    cout << a << " " << b << endl;
}