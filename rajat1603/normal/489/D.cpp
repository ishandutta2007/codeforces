#include<bits/stdc++.h>
using namespace std;
#define scanint(n) scanf("%d",&n)
vector<int> a[3001];
bool visited[3001];
int ans[3001][3001]={0};
int source, destination;
void dfs(int n,int k){
    if(k>2){
        return;
    }
    if(k==2){
        //if(n==destination){
            ans[source][n]++;
        //}
        return ;
    }
    int x=a[n].size();
    for(int i=0;i<x;i++){
            dfs(a[n][i],k+1);
    }
}
int main(){
    int n,m;
    scanint(n);
    scanint(m);
    for(int i=0;i<m;i++){
        int x,y;
        scanint(x);
        scanint(y);
        a[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        //for(int j=1;j<=n;j++){
            //if(i==j) continue;
            source = i;
            //destination = j;
            dfs(i,0);
        //}
    }
    int answ=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            answ+=(ans[i][j]*(ans[i][j]-1))/2;
        }
    }
    printf("%d",answ);
}