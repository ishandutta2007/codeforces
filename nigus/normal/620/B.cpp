#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
std::vector<ll> A;

ll f(ll i){
if(i == 0){return 6;}
ll k = 1;
while(i/(10*k) != 0)
{
    k *= 10;
}
ll ans = 0;
ll b;
while(k >= 1){
    b = (i%(10*k)) / k;
    ans += A[b];
    k/=10;
}
return ans;
}

int main()
{
    ll c1,c2,c3;
    ll n,m,a,b,c,d;
    A.push_back(6);
    A.push_back(2);
    A.push_back(5);
    A.push_back(5);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);
    A.push_back(3);
    A.push_back(7);
    A.push_back(6);
    std::cin >> a >> b;
    ll ans = 0;
    for(c1 = a; c1<=b;c1++){
        ans += f(c1);

    }
    cout << ans << "\n";
    return 0;
}