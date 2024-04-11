#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull min(ull x, ull y){ if (x<y) return x; return y;}
ull max(ull x, ull y){ if (x<y) return y; return x;}
ll min(ll x, ll y){ if (x<y) return x; return y;}
ll max(ll x, ll y){ if (x<y) return y; return x;}
double min(double x, double y){ if (x<y) return x; return y;}
double max(double x, double y){ if (x<y) return y; return x;}
ull gcd(ull x, ull y){
    if (!x) return y;
    if (!y) return x;
    if (x>y) swap(x,y);
    return gcd(x, y%x);
}
ull inv(ull a, ull c){ // a,c are coprime and a<c
    if (a==1){
        return 1;
    }
    return ((c-(c/a))*inv(c%a,c))%c;
}
 
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll a, b, lcm, k = 0;
    cin>>a>>b;
    lcm = a*b;
    if (a>b) swap(a,b);
 
    for (ll i = 1; i <= (ll)sqrt(b-a); i++){
        if ((b-a)%i==0){
            ll g1 = i, g2 = (b-a)/i;
            ll k1 = (g1-(a%g1))%g1, k2 = (g2-(a%g2))%g2;
            if ((a+k1)*(b+k1)/g1 < lcm){
                k = k1;
                lcm = (a+k1)*(b+k1)/g1;
            }
            if ((a+k2)*(b+k2)/g2 < lcm){
                k = k2;
                lcm = (a+k2)*(b+k2)/g2;
            }
        }
    }
 
    cout<<k<<"\n";
}