#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i,A,B) for(int i=A;i<=B;i++)
#define mod 998244353
#define v1d vector<int>
#define v1c vector<char>
#define v2d vector<vector<int>>
#define v1s vector<string>
#define vip vector<pair<int,int> >
#define v2s vector<vector<string> >
#define vsp vector<pair<string,string> >
#define pa pair<int,int>
 
int node_count(v2d &v,v1d &vis,int src){
    queue<int>q;
    q.push(src);
    int c=0;
    vis[src]=1;
    while(!q.empty()){
        int a= q.front();q.pop();
        c++;
        for(auto i:v[a]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    return max(c,(int)1);
} 
 
int bfs(v2d &v,int n,int x,int y){
    v1d vis(n+1,0);
    vis[x]=1;
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int a= q.front();q.pop();\
        if(a==y){
            return node_count(v,vis,y);
        }
        for(auto i:v[a]){
            if(!vis[i]){
                vis[i]=1;\
                q.push(i);
            }
        }
    }
}
 
int32_t main(){
    IOS;
    int n,x,y;cin>>n>>x>>y;
    v2d v(n+1);
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int a=bfs(v,n,x,y);
    int b=bfs(v,n,y,x);//cout<<a<<" "<<b<<endl;
    int ans= n*(n-1);
    ans-= a*b;
    cout<<ans;
    return 0;
}