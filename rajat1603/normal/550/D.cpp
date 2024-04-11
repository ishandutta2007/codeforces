#include "bits/stdc++.h"
using namespace std;
int k;
int n , m;
void check(){
    if(k == 1){
        cout << "YES\n2 1\n1 2";
        exit(0);
    }
    if(!(k & 1)){
        cout << "NO";
        exit(0);
    }
    cout << "YES\n";
    n = k + k + 4;
    m = 1 + 2 * (1 + k - 1 + k - 1 + k - 1 + ((k - 1) * (k - 3)) / 2);
    cout << n << " " << m << "\n";
}
int main(){
    cin >> k;
    check();
    int count = 0;
    for(int i = 3 ; i < k + 2 ; ++i){
        cout << i << " " << k + 2 << "\n";
        cout << 1 << " " << i << "\n";
        cout << 2 << " " << i << "\n";
        cout << i + 2 + k << " " << k + 2 + 2 + k << "\n";
        cout << 1 + 2 + k << " " << i + 2 + k << "\n";
        cout << 2 + 2 + k << " " << i + 2 + k << "\n";
        count += 6;
    }
    cout << "1 2\n";
    cout << 1 + 2 + k << " " << 2 + 2 + k << "\n";
    cout << k + 2 << " " << n << "\n";
    count += 3;
    for(int i = 3 ; i < k + 2 ; ++i){
        if((i != (k + 1)) && !(i & 1)){
            cout << i << " " << i + 1 << "\n";
            cout << i + 2 + k << " " << i + 1 + 2 + k << "\n";
            count += 2;
        }
        for(int j = i + 2 ; j < k + 2 ; ++j){
            cout << i << " " << j << "\n";
            cout << i + 2 + k << " " << j + 2 + k << "\n";
            count += 2;
        }
    }
    assert(m == count);
}