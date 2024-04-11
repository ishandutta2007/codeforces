#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    string s;
    cin>>s;
    int p=0,l=0;
    rep(i,s.size()){
        if(s[i]=='o') p++;
        else l++;
    }
    if(p==0){ cout<<"YES"; return 0;}
    if(l%p==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}