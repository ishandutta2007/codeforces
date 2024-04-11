#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second


int main()
{
    ll n;
    cin >> n;
    ll a,b,c;
    a = 1;
    b = 2;
    c = 0;
    ll i = 0;
    while(c <= n){
        c = a+b;
        a = b;
        b = c;
        i++;
    }
    cout << i;
    return 0;
}