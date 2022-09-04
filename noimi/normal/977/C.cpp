#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

main(){
    int n,k;
    cin>>n>>k;
    vector<ll int> v;
    rep(i,n){
        ll int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    if(k==0){
        if(v[0]==1){
            cout<<-1; return 0;
        }
        else {
            cout<<1; return 0;
        }
    }
    if(v[k-1]==v[k]) {
        cout<<-1;
    }
    else cout<<v[k-1];
    return 0;
}