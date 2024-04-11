#include <cstdio>

int n,m;
int weight[501];
bool used[501];
int books[1010];
int ans[501];

int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;++i) scanf("%d",weight+i);
    int top=1;
    for(i=0;i<m;++i) {
        scanf("%d",books+i);
        if(!used[books[i]]){
            used[books[i]]=true;
            ans[top++]=books[i];
        }
    }
    int sum=0;
    int j;
    for(i=0;i<m;++i){
        for(j=1;j<=n;++j){
            if(ans[j]==books[i]){
                break;
            }
        }
        for(;j>=2;--j) ans[j]=ans[j-1],sum+=weight[ans[j]];
        ans[1]=books[i];
    }
    printf("%d\n",sum);
    return 0;
}