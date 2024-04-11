#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;
int n,ans[1000010],num[1000010],son[1000010][2];
char ch[1000010][5];
int dfs(int x){
    if (ch[x][0]=='I') return num[x];
    if (ch[x][0]=='N') return num[x]=(dfs(son[x][0])^1);
    if (ch[x][0]=='A') return num[x]=(dfs(son[x][0])&dfs(son[x][1]));
    if (ch[x][0]=='O') return num[x]=(dfs(son[x][0])|dfs(son[x][1]));
    if (ch[x][0]=='X') return num[x]=(dfs(son[x][0])^dfs(son[x][1]));
}
int redfs(int x,int a0,int a1){
    if (ch[x][0]=='I'){
        if (num[x]==0) ans[x]=a1;
        if (num[x]==1) ans[x]=a0;
    }
    if (ch[x][0]=='N') redfs(son[x][0],a1,a0);
    int tmp[2];
    if (ch[x][0]=='A'){
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                if ((j&num[son[x][i^1]])==0) tmp[j]=a0;
                else tmp[j]=a1;
            }
            redfs(son[x][i],tmp[0],tmp[1]);
        }
    }
    if (ch[x][0]=='O'){
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                if ((j|num[son[x][i^1]])==0) tmp[j]=a0;
                else tmp[j]=a1;
            }
            redfs(son[x][i],tmp[0],tmp[1]);
        }
    }
    if (ch[x][0]=='X'){
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                if ((j^num[son[x][i^1]])==0) tmp[j]=a0;
                else tmp[j]=a1;
            }
            redfs(son[x][i],tmp[0],tmp[1]);
        }
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%s",ch[i]);
        int o,p;
        if (ch[i][0]=='I') scanf("%d",&num[i]);
        else if (ch[i][0]=='N') scanf("%d",&son[i][0]);
        else scanf("%d%d",&son[i][0],&son[i][1]);
    }
    dfs(1);
    redfs(1,0,1);
    for (int i=1;i<=n;i++)
    if (ch[i][0]=='I') printf("%d",ans[i]);
    return 0;
}