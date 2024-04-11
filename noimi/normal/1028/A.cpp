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
ll MOD=998244353;
#define INF 2*1e9
#define N 510000
using namespace std;
main(){
    int n,m;cin>>n>>m;
    int a[200][200]={};
    rep2(i,1,n){
        string s;
        cin>>s;
        rep2(j,1,m){
            if(s[j-1]=='B') a[i][j]=1;
        }
    }
    int b[2][2];
    rep2(i,1,n){
        rep2(j,1,m){
            if(a[i-1][j]==0&&a[i][j-1]==0&&a[i][j]){
                b[0][0]=i;b[0][1]=j;
            }
            if(a[i+1][j]==0&&a[i][j+1]==0&&a[i][j]){
                b[1][0]=i;b[1][1]=j;
            }
        }
    }
    cout<<(b[0][0]+b[1][0])/2<<" "<<(b[0][1]+b[1][1])/2;
    return 0;
}