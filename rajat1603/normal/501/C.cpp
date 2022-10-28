#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 65537;
int degree[N];
int xorsum[N];
int n;
queue<int> q;
int ans = 0 ;
queue < pair < int , int > > edges;
int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d %d",&degree[i] , &xorsum[i]);
        if(degree[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!degree[node]){
            continue;
        }
        int next = xorsum[node];
        xorsum[node] = 0;
        edges.push(mp(node,next));
        ans++;
        xorsum[next] ^= node;
        degree[next]--;
        if(degree[next]==1){
            q.push(next);
        }
    }
    printf("%d\n",ans);
    while(!edges.empty()){
        printf("%d %d\n",edges.front().first , edges.front().second);
        edges.pop();
    }
}