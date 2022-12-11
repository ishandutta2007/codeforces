#include <bits/stdc++.h>

using namespace std;

int main(){
    int testc;
    cin >> testc;
    for(int i = 1; i <= testc; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        if(a <= b){
            c -= b - a + 1;
            if(c < 0){
                cout << 0 << "\n";
                continue;
            }
            a=b+1;
        }
        if(c < (a - b)){
            cout << c + 1 << "\n";
        }
        else{
            int low = (c - (a - b)) / 2 + 1;
            cout << c - low + 1 << "\n";
        }
    }
    return 0;
}