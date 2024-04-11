#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD=1000000007;

LL powMod(LL x, LL y, LL mod) {
    if (y<1) return 1;
    if (y%2) return x*powMod(x, y-1, mod)%mod;
    return powMod(x*x%mod, y/2, mod);
}

	
int main() {
    LL y[]={0,1,2,9,64,625,7776,117649,2097152};
    int n, k;
    scanf("%d%d", &n, &k);
    cout<<y[k]*powMod(n-k, n-k, MOD)%MOD<<endl;
    return 0;
}