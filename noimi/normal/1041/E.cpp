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
#define N 600010
using namespace std;
void print(int x,int y){
    printf("%d %d\n",x,y);
    return;
}
main(){
    int n;
  cin>>n;
    int t[N];
    rep(i,n-1){
        int a,b;cin>>a>>b;
        if(a==b){cout<<"NO";return 0;}
        if(a>b)swap(a,b);
        if(b!=n){cout<<"NO";return 0;}
        t[i]=a;
    }
    sort(t,t+(n-1));
    int b[N];
    rep2(i,1,n-1){
        b[i]=upper_bound(t,t+n-1,i)-lower_bound(t,t+n-1,i);
    }
    vector<int> v[N];
    queue<int> q;
    for(int i=n-1;i>0;i--){
        if(b[i]==0){
            if(q.empty()){
                cout<<"NO";return 0;
            }
            int s=q.front();q.pop();
            v[s].pb(i);
        }
        else{
            rep(j,b[i]-1)q.push(i);
        }
    }
    cout<<"YES"<<endl;
    rep2(i,1,n-1){
        if(b[i]==0){
            continue;
        }
        else if(b[i]==1)print(n,i);
        else{
            print(n,v[i][0]);
            rep(j,v[i].size()-1){
                print(v[i][j],v[i][j+1]);
            }
            print(v[i][v[i].size()-1],i);
        }
    }
    return 0;
}