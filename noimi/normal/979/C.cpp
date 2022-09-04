#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");


main(){
    ll int n,x,y;
    cin>>n>>x>>y;
    vector<vector<int>> v(310000);
    rep(i,n-1){
        ll int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int map[310000]={};
    map[x]=1;
    ll int s;
    rep(i,v[x].size()){
        ll int top=v[x][i];
        map[top]=1;
        if(top==y) {s=y; break;}
        queue<int> q;
        q.push(top);
        while(!q.empty()){
            int t=q.front();
            map[t]=1;
            if(t==y) {s=top;break;}
            q.pop();
            rep(j,v[t].size()){
                if(!map[v[t][j]]){
                    q.push(v[t][j]);
                }
            }
        }
    }
    queue<int> q;
    ll int yans=1;
    map[y]=3;
    q.push(y);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            map[t]=3;
            rep(j,v[t].size()){
                if(map[v[t][j]]==0){
                    q.push(v[t][j]);
                    yans++;
                }
            }
        }
    map[x]=2;
    map[s]=2;
        q.push(s);
        ll int ans=n-1;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            map[t]=2;
            rep(j,v[t].size()){
                if(map[v[t][j]]!=2){
                    q.push(v[t][j]);
                    ans--;
                }
            }
        }
        ll int k=n*(n-1)-yans*ans;
        cout<<k;
        return 0;
    
}