#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    /*char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }*/
    int x;
    scanf("%d",&x);
    return x;
}
vector<int> v[101][101];
int src,dest;
int ans;
bool visited[101];
bool found;
void dfs(int node,int c){
    if(visited[node]){
        return;
    }
    if(node==dest){
        found=1;
        return;
    }
    visited[node]=1;
    int x = v[c][node].size();
    for(int i=0;i<x;i++){
        dfs(v[c][node][i],c);
    }
}
int main(){
    int n=scan(),m=scan();
    int mm=m;
    while(mm--){
        int a=scan(),b=scan(),c=scan();
        v[c][a].push_back(b);
        v[c][b].push_back(a);
    }
    int q=scan();
    while(q--){
        src=scan(),dest=scan();
        ans=0;
        for(int i=1;i<=m;i++){
            found=0;
            memset(visited,0,sizeof(visited));
            dfs(src,i);
            if(found){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}