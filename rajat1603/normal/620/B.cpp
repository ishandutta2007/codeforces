#include "bits/stdc++.h"
using namespace std;
int a , b;
int ans = 0;
int f[10] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
int solve(int i){
    int ret = 0;
    while(i){
        ret += f[i % 10];
        i /= 10;
    }
    return ret;
}
int main(){
    cin >> a >> b;
    for(int i = a ; i <= b ; ++i){
        ans += solve(i);
    }
    cout << ans;
}