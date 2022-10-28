#include "bits/stdc++.h"
using namespace std;
long long n;
void solve(long long pos , int cur){
    if(pos + cur - 1 >= n){
        cout << n - pos + 1;
        exit(0);
    }
    solve(pos + cur , cur + 1);
}
int main(){
    cin >> n;
    solve(1 , 1);
}