/*
   .
#???????
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

ll req;

ll fib(ll a,ll b,ll x){
    if(x >= req){
        return a;
    }
    else{
        return fib(a+b,a,x+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll a,b;
    cin >> a >> b >> req;
    cout << fib(b,a,1);
    return 0;
}