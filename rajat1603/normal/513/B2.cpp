#include "bits/stdc++.h"
using namespace std;
int n;
long long m;
void solve(int num , long long left){
    if(num == n){
        cout << num << " ";
        return;
    }
    int x = n - num - 1;
    if((1LL << x) >= left){
        cout << num << " ";
        solve(num + 1 , left);
    }
    else{
        solve(num + 1 , left - (1LL << x));
        cout << num << " ";
    }
}
int main(){
    cin >> n >> m;
    solve(1 , m);
}