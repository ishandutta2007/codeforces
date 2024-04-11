#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define getchar_unlocked() getchar()
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
const int N = 50001;
const int K = 501;
int n,k,dist[N][K]={0};
list<int> v[N];
void dfs1(int node,int parent){
    for(list<int>::iterator it = v[node].begin();it!=v[node].end();++it){
        int next = *it;
        if(next!=parent){
            dfs1(next,node);
            for(int i=1;i<=k;++i){
                dist[node][i]+=dist[next][i-1];
            }
        }
    }
    dist[node][0]=1;
}
long long ans=0;
void dfs(int node,int parent){
    int temp[K]={0};
    for(list<int>::iterator it = v[node].begin();it!=v[node].end();++it){
        int next = *it;
        if(next!=parent){
            dfs(next,node);
            for(int i=0;i<=k;++i){
                temp[i]+=dist[next][i];
            }
        }
    }
    ans+=(dist[node][k]<<1);
    for(list<int>::iterator it = v[node].begin();it!=v[node].end();++it){
        int next=*it;
        if(next!=parent){
            for(int i=1;i<k;++i){
                ans+=1LL*dist[next][i-1]*(temp[k-i-1]-dist[next][k-i-1]);
            }
        }
    }
}
int main(){
    n=scan(),k=scan();
    for(int i=1;i<n;++i){
        int a=scan(),b=scan();
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs1(1,-1);
    dfs(1,-1);
    ans>>=1;
    printf("%I64d\n",ans);
}