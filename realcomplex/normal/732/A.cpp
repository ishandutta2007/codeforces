#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int c,t;
    cin >> c >> t;
    for(int j = 0;j<100000;j++){
        if(((j*10)+t) % c == 0){
            cout << ((j*10)+t) / c;
            return 0;
        }
        if((j*10) % c == 0 && j!=0){
            cout << (j*10) / c;
            return 0;
        }
    }
    return 0;
}