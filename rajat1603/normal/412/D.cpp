#include<bits/stdc++.h>
using namespace std;
int scan(){
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
int n;
vector<int> v[100000];
bool visited[100000];
void dfs(int node){
    visited[node]=1;
    int x=v[node].size();
    for(int i=0;i<x;i++){
        int next = v[node][i];
        if(!visited[next]){
            dfs(next);
        }
    }
    printf("%d ",node);
}
int main(){
    n=scan();
    int m=scan();
    while(m--){
        int a=scan();
        int b=scan();
        v[a].push_back(b);
    }
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++){
       if(!visited[i]) dfs(i);
    }
}