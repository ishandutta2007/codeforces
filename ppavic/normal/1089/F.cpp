#include <cstdio>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair < ll , ll > pii;

ll n, k;
vector < ll > v;

pii ext_gcd(ll A,ll B){
    ll s = 0, t = 1, r = B;
    ll s2 = 1, t2 = 0, r2 = A;
    while(r != 0){
        ll kof = r2 / r;
        swap(r, r2);
        r = r - kof * r2;
        swap(s, s2);
        s = s - kof * s2;
        swap(t, t2);
        t = t - kof * t2;
    }
    return {s2, t2};
}


int main(){
    scanf("%lld", &n);
    k = n - 1;
    for(ll i = 2;i*i<=n;i++){
        if(n % i == 0) {
            v.push_back(i);
        }
        while(n % i == 0) n /= i;
    }
    if(n != 1) v.push_back(n);
    n = k + 1;
    if(v.size() == 1){
        printf("NO\n");
        return 0;
    }
    pii sol = ext_gcd(v[0], v[1]);
    sol.X *= k;
    sol.Y *= k;
    ll kof = 0;
    if(sol.X < 0){
        kof = -sol.X / v[1];
        if(sol.X % v[1] != 0) kof++;
    }
    else if(sol.Y < 0){
        kof = sol.Y / v[0] ;
        if(v[0] % sol.Y != 0) kof--;
    }
    printf("YES\n2\n%lld %lld\n%lld %lld\n", sol.X + kof * v[1], n / v[0], sol.Y - kof * v[0], n / v[1]);
    return 0;

}