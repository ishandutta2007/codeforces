#include <iostream>

using namespace std;
typedef long long ll;

bool fair(ll x){
    ll y = x;
    while(y != 0){
        if(y%10 == 0){
            y /= 10;
            continue;
        }
        if(x%(y%10) != 0) return false;
        y /= 10;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long n;
        scanf("%lld", &n);
        for(ll i=n;i<=n+2520;i++){
            if(fair(i)){
                printf("%lld\n", i);
                break;
            }
        }
    }
}