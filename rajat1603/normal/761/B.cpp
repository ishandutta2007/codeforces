#include "bits/stdc++.h"
using namespace std;
const int N = 205;
int n , l;
int a[N];
int b[N];
bool ok(){
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}
void shift(){
    for(int i = 1 ; i <= n ; ++i){
        --a[i];
    }
    if(a[1] == -1){
        for(int i = 2 ; i <= n ; ++i){
            a[i - 1] = a[i];
        }
        a[n] = l - 1;
    }
}
int main(){
    cin >> n >> l;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        cin >> b[i];
    }
    for(int i = 0 ; i <= l ; ++i){
        if(ok()){
            cout << "YES\n";
            return 0;
        }
        shift();
    }
    cout << "NO\n";
}