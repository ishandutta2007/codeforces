#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 200000
using namespace std;
main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<char> v;
    int num=0,l=k/2;
    rep(i,n){
        if(k==0) continue;
        if(s[i]=='('&&l){
            v.pb('(');l--;k--;num++;
        }
        else if(s[i]==')'&&num){
            num--;k--;v.pb(')');
        }
    }
    rep(i,v.size()){
        cout<<v[i];
    }
    return 0;
}