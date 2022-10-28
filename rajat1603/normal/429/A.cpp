#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
bool init[N];
bool goal[N];
int n;
list<int> v[N];
int ans = 0 ;
queue<int> print;
void dfs(int node,int parent,bool odd,bool even,bool level){
    if(goal[node]!=init[node]^(level?odd:even)){
        ans++;
        print.push(node);
        level?odd^=1:even^=1;
    }
    for(list<int>::iterator it = v[node].begin();it!=v[node].end();++it){
        if(*it!=parent){
            dfs(*it,node,odd,even,level^1);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 1 ; i < n ; ++i ){
        int a , b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; ++i ){
        scanf("%d",&init[i]);
    }
    for(int i = 1 ; i <= n ; ++i ){
        scanf("%d ",&goal[i]);
    }
    dfs(1,-1,0,0,0);
    printf("%d\n",ans);
    while(!print.empty()){
        printf("%d\n",print.front());
        print.pop();
    }
}