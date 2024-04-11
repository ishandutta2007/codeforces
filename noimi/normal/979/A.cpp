#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

string s;

main(){
    ll int n;
    cin>>n;
    if(n%2) cout<<((n+1)/2);
    else if(n==0) cout<<0;
    else cout<<n+1;
    return 0;
}