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
    int a[1100]={};
    rep(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[(n-1)/2];
    return 0;


}