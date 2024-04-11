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
        int n;scanf("%d",&n);
        int a[1100000];
        rep(i,n){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        vector<int> v;
        rep(i,n){
            if(a[i]==a[i+1]&&i+1<n){
                v.pb(a[i]);i++;
            }
            
        }
        int x=0,y=100000;
        rep(i,v.size()-1){
            if(y*v[i]>x*v[i+1]){
                x=v[i];y=v[i+1];
            }
        }
        printf("%d %d %d %d\n",x,x,y,y);
    }
    return 0;
}