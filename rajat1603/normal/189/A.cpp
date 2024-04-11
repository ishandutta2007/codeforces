#include "bits/stdc++.h"
using namespace std;
int n , a , b , c;
int mem[1 << 12];
int solve(int n){
    if(n <= 0){
        return (n < 0) ? -9999 : 0;
    }
    if(mem[n] != -1){
        return mem[n];
    }
    return mem[n] = 1 + max(solve(n - a) , max(solve(n - b) , solve(n - c)));
}
int main(){
    cin >> n >> a >> b >> c;
    memset(mem , -1 , sizeof(mem));
    cout << solve(n);
}