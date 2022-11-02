#include <iostream>

using namespace std;

constexpr int mod = 1e9 + 7;

long long f(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++){
        res*=i;
        res%=mod;
    }
    return res;
}

long long t(int n){
    if(!n)return 1;
    long long p = t(n>>1);
    p*=p;
    p%=mod;
    if(n&1){p<<=1;p%=mod;}
    return p;
}


int main() {
    int n;
    cin>>n;
    cout<<(f(n)-t(n-1)+mod)%mod<<endl;
}