#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,q,T,k;

string s;

ll f(ll i , ll k2){
if(k2 == 0)return 0;
if(i == -1)return big;
if(s[i] == '0'){
    return f(i-1,k2-1);
}
return 1 + f(i-1,k2);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll c1,c2,c3;
    ll a,b,c;

    cin >> s >> k;

    ll ans = s.length()-1;
    ans = min(ans , f(s.length()-1 , k));
    cout << ans << "\n";

    return 0;
}