#define MOD 998244353
#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;
const int sz=2e5+5;
ll pw(ll a, ll b) {
    if(!b)return 1;
    ll tmp = pw(a,b>>1);
    tmp*=tmp;
    tmp%=MOD;
    if(b&1)tmp*=a;
    return tmp%MOD;
}
ll f[sz], inv[sz];

void prec() {
    int big=2e5+1;
    f[0]=1;
    for(int i =1;i<=big;i++) {
        f[i]=(f[i-1]*i)%MOD;
    }
}


int main() {
    ll n,m;
    cin>>n>>m;
    if(m<n-1||n<=2){
        cout<<0<<endl;
        return 0;
    }
    prec();
    ll res=f[m];
    res *= pw(f[n-1],MOD-2);
    res%=MOD;
    res*= pw(f[m-n+1],MOD-2);
    res%=MOD;
    res*=(n-2);
    res%=MOD;
    res*=pw(2,n-3);
    res%=MOD;
    cout<<res<<endl;
}