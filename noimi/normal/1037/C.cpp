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
#define N 310000
using namespace std;

main(){
    int n;cin>>n;
    string s,t;
    cin>>s>>t;
    int ans=0;
    rep(i,n){
        if(s[i]==t[i])continue;
        if(i==n-1){ans++;break;}
        if(s[i+1]!=t[i+1]&&s[i]!=s[i+1]){
            ans++;i++;
        }
        else ans++;
    }
    cout<<ans;
    return 0;
}