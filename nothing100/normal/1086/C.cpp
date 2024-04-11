#include<bits/stdc++.h>
using namespace std;
int t,k,ll,f[30],use[30];
char ch[1000010],a[1000010],b[1000010];
int dfs(int x,int f0,int f1){
    if ((f0==0&&f1==0)||x==ll) return 1;
    int l=0,r=k-1,now=ch[x]-'a';
    if (f0) l=a[x]-'a';
    if (f1) r=b[x]-'a';
    if (f[now]==-1){
        for (int i=l;i<=r;i++)
        if (!use[i]){
            use[i]=1;
            f[now]=i;
            if (dfs(x+1,f0&(i==l),f1&(i==r))) return 1;
            use[i]=0;
            f[now]=-1;
        }
    }
    else{
        if (f[now]<l||f[now]>r) return 0;
        if (dfs(x+1,f0&(f[now]==l),f1&(f[now]==r))) return 1;
    }
    return 0;
}
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d",&k);
        for (int i=0;i<k;i++) f[i]=-1,use[i]=0;
        scanf("%s",ch);
        scanf("%s",a);
        scanf("%s",b);
        ll=strlen(a);
        if (dfs(0,1,1)){
            printf("YES\n");
            for (int i=0;i<k;i++){
                if (f[i]==-1){
                    for (int j=0;j<k;j++)
                    if (use[j]==0){
                        use[j]=1;
                        f[i]=j;
                        break;
                    }
                }
                printf("%c",'a'+f[i]);
            }
            printf("\n");
        }
        else
            printf("NO\n");
    }
}