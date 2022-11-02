#include<stdio.h>
int pre[3010];
inline int find(int x){
    return pre[x]==-1?x:pre[x]=find(pre[x]);
}
int main(){
    int n,m,k,i,j,l;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)pre[i]=-1;
    for(i=0;i<=n-k;i++){
        for(j=i,l=i+k-1;j<l;j++,l--){
            int jj=find(j),ll=find(l);
            if(jj!=ll){
                pre[jj]=ll;
            }
        }
    }
    long long ans=1;
    for(int i=0;i<n;i++)if(pre[i]==-1)ans=(ans*m)%1000000007;
    printf("%d\n",(int)ans);
}