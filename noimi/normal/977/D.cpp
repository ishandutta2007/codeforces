#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
main(){
    int n;
    cin>>n;
    vector<pair<int,ll int>> v;
    rep(i,n){
        ll int a;
        cin>>a;
        ll int b=a;
        int count=0;
        while((b%3)==0){
            count--;
            b/=3;
        }
        pair<int,ll int> p;
        p.first=count;
        p.second=a;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    rep(i,n){
        cout<<v[i].second<<" ";
    }
    return 0;
}