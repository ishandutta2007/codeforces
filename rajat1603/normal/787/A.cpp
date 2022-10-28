#include "bits/stdc++.h"
using namespace std;
int a , b;
int c , d;
int main(){
    cin >> a >> b;
    cin >> c >> d;
    for(int i = 0 ; i <= 1e5 ; ++i){
        int val = b + a * i;
        val -= d;
        if(val >= 0 && val % c == 0){
            cout << val + d << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}