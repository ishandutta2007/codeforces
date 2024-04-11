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
#define N 610000
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int t;
    cin>>t;
    rep(iii,t){
        int n;
        cin>>n;
        string s;cin>>s;
        n/=2;
        bool flag=true;
        rep(i,n){
            int m=s[i]-s[n*2-1-i];
            if(m!=0&&m!=2&&m!=-2) flag=false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}