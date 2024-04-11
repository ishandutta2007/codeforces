#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n,k;
    cin>>n>>k;
    rep(i,k){
        if(n%10){
            n--;
        }
        else if(n!=0){
            n/=10;
        }
        else {
            cout<<0; return 0;
        }
    }
    cout<<n;
    return 0;
}