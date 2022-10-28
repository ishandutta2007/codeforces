#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main(){
   int n,m;
    scanf("%d%d",&n,&m);
    char a[21];
   scanf("%s",a);
    char b[21];
    scanf("%s",b);
    vector<int> v[401];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]=='<'){
                if(j>0){
                    v[i*m+j].push_back(i*m+j-1);
                }
            }
            if(a[i]=='>'){
                if(j<m-1){
                    v[i*m+j].push_back(i*m+j+1);
                }
            }
            if(b[j]=='v'){
                if(i<n-1){
                    v[i*m+j].push_back((i+1)*(m)+j);
                }
            }
            if(b[j]=='^'){
                if(i>0){
                    v[i*m+j].push_back((i-1)*(m)+j);
                }
            }
        }
    }
    bool visited[401]={0};
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int u=q.front();
        int x=v[u].size();
        q.pop();
        for(int i=0;i<x;i++){
            if(visited[v[u][i]]==0){
                q.push(v[u][i]);
                visited[v[u][i]] = 1;
            }
        }
    }
    bool f=1;
    for(int i=0;i<n*m;i++){
        if(!visited[i]){
            printf("NO");
            f=0;
            break;
        }
    }
    if(f)
    printf("YES");
}