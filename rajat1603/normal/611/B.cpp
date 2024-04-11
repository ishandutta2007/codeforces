#include "bits/stdc++.h"
using namespace std;
set < long long > s;
long long a , b;
int ans;
int main(){
    for(int i = 1 ; i < 63 ; ++i){
        long long temp = (1LL << i) - 1;
        for(int j = 0 ; j < i - 1 ; ++j){
            s.insert(temp ^ (1LL << j));
        }
    }
    cin >> a >> b;
    for(auto it : s){
        if(it >= a && it <= b){
            ++ans;
        }
    }
    cout << ans;
}