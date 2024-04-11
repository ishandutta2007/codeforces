#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;
vector<pair<int,bool> > list[100001];
vector<int> ans;
bool visited[100001]={0};
int dfs(int node,bool bolean){
    visited[node]=1;
    int y=0;
    int x=list[node].size();
    for(int i=0;i<x;i++){
        if(!visited[list[node][i].first]){
            if(list[node][i].second){
                y++;
                dfs(list[node][i].first,1);
            }
            else{
                y+=dfs(list[node][i].first,0);
            }
        }
    }
    if(y==0&&bolean) ans.push_back(node);
    return y;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        c--;
        list[a].push_back(make_pair(b,c));
        list[b].push_back(make_pair(a,c));
    }
    dfs(1,0);
    int x=ans.size();
    printf("%d\n",x);
    for(int i=0;i<x;i++){
        printf("%d ",ans[i]);
    }
    
}