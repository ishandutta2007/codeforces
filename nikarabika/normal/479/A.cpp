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
    int a, b, c;
    cin>>a>>b>>c;
    int max_=max(a+b+c, max(a+b*c, max(a*b+c, max(a*b*c, max((a+b)*c, a*(b+c))))));
    cout<<max_<<endl;
    return 0;
}