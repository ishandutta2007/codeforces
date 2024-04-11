#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");
 
main(){
    int n;
    cin>>n;
    int zero=0;
    if(n==1){
        int a;
        cin>>a;
        if(a==0) {cout<<0; return 0;}
        else cout<<1;
        return 0;
    }
    char a[n];
    rep(i,n){
        cin>>a[i];
        if(a[i]=='0') zero++;
    }
    cout<<1;
    rep(i,zero)
    cout<<0;
    return 0;
}