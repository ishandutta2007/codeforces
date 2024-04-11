#include "bits/stdc++.h"
using namespace std;
const int N = 10;
int n;
int x[N];
int y[N];
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x[i] >> y[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            if(x[i] == x[j] || y[i] == y[j]){
                continue;
            }
            cout << abs(x[i] - x[j]) * abs(y[i] - y[j]);
            return 0;
        }
    }
    cout << -1;
}