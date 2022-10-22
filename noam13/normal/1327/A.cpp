#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    if (n%2!=k%2 || (n<k*k)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}
int32_t main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
6
3 1
4 2
10 3
10 2
16 4
16 5

*/