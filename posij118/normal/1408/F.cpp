#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int x = 1;
    while((1 << x) <= n) x++;
    x--;

    cout << x*(1 << x) << endl;

    for(int i = 0; i<x; i++){
        for(int j = 0; j<(1 << x); j++){
            if(j & (1 << i)){
                cout << j + 1 << " " << j - (1 << i) + 1 << endl;
            }
        }
    }

    for(int i = 0; i<x; i++){
        for(int j = 0; j<(1 << x); j++){
            if(j & (1 << i)){
                cout << n - j << " " << n - (j - (1 << i)) << endl;
            }
        }
    }

}