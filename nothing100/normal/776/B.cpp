#include<bits/stdc++.h>
#define LL long long
#define mo 1594323
using namespace std;
int n,check[200010],tot,prime[200010];
void shai(){
    memset(check,0,sizeof(check));
    int tot=0;
    for (int i=2;i<=n+1;i++){
        if (!check[i]) prime[tot++]=i;
        for (int j=0;j<tot;j++){
            if (i*prime[j]>n+1) break;
            check[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}
int main(){
    scanf("%d",&n);
    if (n>2){
        shai();
        printf("2\n");
        for (int i=2;i<=n+1;i++) printf("%d ",check[i]+1);
    }
    else{
        printf("1\n");
        for (int i=0;i<n;i++) printf("1 ");
    }
    return 0;
}