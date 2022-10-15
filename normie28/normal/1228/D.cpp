#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
set<int>g[N];
int color[N];
bool f=0;
void dfs(int x){
    set<int>cl;
    for (int y:g[x]){
        if (color[y]){
            cl.insert(color[y]);
        }
    }
    if (cl.size()!=2){
        f=0;
    }
    else {
        int sum=0;
        for (int c:cl){
            sum+=c;
        }
        color[x]=6-sum;
    }
    for (int y:g[x]){
        if (!color[y] && f){
            dfs(y);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    for (int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
    }
    int ver=1;
    for (int x=1; x<=n; x++){
        if (g[x].size()<g[ver].size()){
            ver=x;
        }
    }
    f=0;
    for (int y1:g[ver]){
        for (int y2:g[ver]){
            if (y1!=y2 && g[y1].find(y2)!=g[y1].end()){
                f=1;
                color[ver]=1, color[y1]=2, color[y2]=3;
                break;
            }
        }
        if (f){
            break;
        }
    }
    if (!f){
        cout<<-1;
        return 0;
    }
    if (n==3){
        for (int x=1; x<=3; x++){
            cout<<color[x]<<" ";
        }
        return 0;
    }
    int st;
    for (int x:g[ver]){
        if (!color[x]){
            st=x;
            break;
        }
    }
    dfs(st);
    if (!f){
        cout<<-1;
        return 0;
    }
 
    for (int x=1; x<=n; x++){
        if (!color[x]){
            cout<<-1;
            return 0;
        }
    }
    int s1=0, s2=0, s3=0;
    for (int x=1; x<=n; x++){
        s1+=color[x]==1;
        s2+=color[x]==2;
        s3+=color[x]==3;
    }
    if (!s1 || !s2 || !s3){
        cout<<-1;
        return 0;
    }
    vector<int>hu(4, 0);
    hu[1]=s1, hu[2]=s2, hu[3]=s3;
    for (int x=1; x<=n; x++){
        int cv=color[x];
        int sm=0;
        for (int c=1; c<=3; c++){
            if (c!=cv)
                sm+=hu[c];
        }
        if (g[x].size()!=sm){
            cout<<-1;
            return 0;
        }
    }
    for (int x=1; x<=n; x++){
        printf("%d ", color[x]);
    }
}