#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
vector<int> g[200];
long long a[1000000];
int vis[200],ans,fa[200];
int main(){
int cnt=0,n;
scanf("%d",&n);
rep(i,1,n+1){
scanf("%lld",&a[i]);
if(a[i])a[++cnt]=a[i];}
n=cnt;
if(n>150){
cout<<3;
return 0;
}
rep(i,1,n+1){
rep(j,i+1,n+1){
if(a[i]&a[j]){
g[i].push_back(j);
g[j].push_back(i);
}
}
}
ans=200;
rep(i,1,n+1){
 memset(vis,0,sizeof vis);
      if(!vis[i]){
           queue<int>  q;
            vis[i]=1;
            q.push(i);
            while(!q.empty()){
                    int u=q.front();q.pop();
                    for(auto v:g[u]){
                         if(fa[u]!=v){
                              if(vis[v])ans=min(ans,vis[u]+vis[v]-1);
                              else q.push(v),fa[v]=u,vis[v]=vis[u]+1;
                         }
                    }
           }
        }
   }
if(ans==200)cout<<-1;
else cout<<ans;
}