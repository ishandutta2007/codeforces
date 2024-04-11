#include "bits/stdc++.h"
using namespace std;
long long num;
long long power10(int x){
    long long res = 1;
    for(int i = 1 ; i <= x ; ++i){
        res *= 10LL;
    }
    return res;
}
long long dijits(long long num){
    int res = 0;
    while(num){
        res++;
        num /= 10;
    }
    return res;
}
long long solve(long long num){
    if(num < 10LL){
        return num;
    }
    int x = power10(dijits(num) - 1);
    return solve(x - 1) + (num - x + 1) * dijits(num);
}
int main(){
    cin >> num;
    cout << solve(num);
}