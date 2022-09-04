#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");
 
main(){
    ll int n,m,k;
    cin>>n>>m>>k;
    if(k<n){
        cout<<k+1<<" "<<1;
        return 0;
    }
    else {
        k-=n-1;
        ll int t=(k-1)/(2*m-2);
        ll int s=(k-1)%(2*m-2)+1;
        if(s<m){
            cout<<n-t*2<<" "<<s+1;
            return 0;
        }
        else{
            s-=m;
            cout<<n-t*2-1<<" "<<m-s;
            return 0;
        }
    }
    return 0;
}