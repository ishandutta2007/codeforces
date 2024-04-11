#include<bits/stdc++.h>
using namespace std;
vector<int> v[305],ans;
bool ansf=1;
bool dfs(int last,int p,int fa){
    if(last==p)return 1;
    for(int i=0;i<v[p].size();i++){
        int t=v[p][i];
        if(fa==t)continue;
        if(dfs(last,t,p)){
            ans.push_back(p);
            return 1;
        }
    }
    return 0;
}
int main(){
    int n,x,y;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        v[y].push_back(x);
        v[x].push_back(y);
    }
    ans.push_back(1);
    int last=1,t;
    while(cin>>t){
        dfs(last,t,-1);
        last=t;
    }
    dfs(last,1,-1);
    if(ans.size()!=(n<<1)-1)cout<<-1;else{
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
    }
    return 0;
}