#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m;

ll power(ll n,ll k){
        if(k==0)return 1;
        ll sqp = power(n,k/2);
        if(k%2==0)
                return (sqp*sqp)%m;
        return (((sqp*sqp)%m)*n)%m;
}

int main(){
        cin >> n >> m;
        ll ans = power(ll(3),n);
        cout << ((ans==0) ? m-1 : ans-1) << "\n";
        return 0;
}