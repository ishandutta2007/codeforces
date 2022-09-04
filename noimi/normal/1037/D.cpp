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

int grade[N],par[N];
vector<int> g[N];

void bfs(int a,int b,int c){
    if(grade[a]>b){
        grade[a]=b;
        par[a]=c;
        rep(i,g[a].size()){
            bfs(g[a][i],b+1,a);
        }
    }
}
main(){
    int n;cin>>n;
    rep2(i,0,n)grade[i]=INF;
    rep(i,n-1){
        int a,b;cin>>a>>b;
        g[a].pb(b);g[b].pb(a);
    }
    bfs(1,0,0);
    int temp=0,temp2=0;
    int num[N]={};
    rep(i,n){
        int a;cin>>a;
        num[a]=i;
        if(temp>grade[a]){
            cout<<"No";return 0;
        }
        else if(temp<grade[a]) {temp=grade[a];temp2=num[par[a]];}
        else {
            if(num[par[a]]<temp2){
                cout<<"No";return 0;
            }
            temp2=num[par[a]];
        }
    }
    cout<<"Yes";return 0;
    return 0;
}