#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

int main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    cout<< ll((n / 2) + n * (n % 2) * pow(-1, n % 2))<<endl;
    return 0;
}