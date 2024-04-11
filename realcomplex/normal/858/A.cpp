#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair
#define MAXN 100005

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll a,b;
    a = 0;
    b = 0;
    ll rez = n;
    while(rez%2==0){
        a++;
        rez/=2;
    }
    rez =n;
    while(rez%5==0){
        b++;
        rez/=5;
    }
    ll cur = min(a,b);
    while(a<b&&cur<k){
        n*=2;
        a++;
        cur++;
    }
    while(b<a&&cur<k){
        n*=5;
        b++;
        cur++;
    }
    while(cur<k){
        n*=10;
        cur++;
    }
    cout << n;
    return 0;
}