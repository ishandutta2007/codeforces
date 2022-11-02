#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1e+15
using namespace std;
int n,sum[22],ques[22][1010],ans[1010];
void dfs(int x,int y,int z){
    if (x==y) return;
    int mid=(x+y)/2;
    for (int i=x;i<=mid;i++){
        ques[2*z+1][i]=1;
        sum[2*z+1]++;
    }
    for (int i=mid+1;i<=y;i++){
        ques[2*z+2][i]=1;
        sum[2*z+2]++;
    }
    dfs(x,mid,z+1);
    dfs(mid+1,y,z+1);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) ans[i]=1100000000;
    dfs(1,n,0);
    for (int i=1;i<=20;i++){
        if (sum[i]!=0){
            printf("%d\n",sum[i]);
            for (int j=1;j<=n;j++)
            if (ques[i][j]) printf("%d ",j);
            printf("\n");
            fflush(stdout);
            for (int j=1;j<=n;j++){
                int tmp;
                scanf("%d",&tmp);
                if (!ques[i][j]) ans[j]=min(ans[j],tmp);
            }

        }
        else break;
    }
    printf("-1\n");
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    fflush(stdout);
}