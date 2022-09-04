#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
int MOD=1000000000+7;
int INF=1e6;

using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n;
    cin>>n;
    int s[4000],c[4000];
    rep(i,n){
        cin>>s[i];
    }
    rep(i,n){
        cin>>c[i];
    }
    int second[4000];
    fill(second,second+4000,MOD);
    int ans=MOD;
    rep(i,n){
        for(int j=i-1;j>=0;j--){
            if(s[j]<s[i]){
                ans=min(ans,second[j]+c[i]);
                second[i]=min(second[i],c[i]+c[j]);
            }
        }
    }
    if(ans>=MOD){
        cout<<-1; return 0;
    }
    cout<<ans;
    return 0;
}