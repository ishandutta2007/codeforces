#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
LL n, m;

LL powMod(LL x, LL y, LL mod) {
    if (y<1) return 1;
    if (y%2) return x*powMod(x, y-1, mod)%mod;
    return powMod(x*x%mod, y/2, mod);
}


int main() {
    cin>>n>>m;
    cout<<(powMod(3, n, m)-1+m)%m<<endl;

    return 0;
}