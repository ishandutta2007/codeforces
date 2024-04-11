#include<bits/stdc++.h>
using namespace std;
int pos[100001];
int who[100001];
int main(){
    long long ans=0;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    ans=m;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        pos[x]=i;
        who[i]=x;
    }
    while(m--){
        int x;
        scanf("%d",&x);
        int po=pos[x];
        if(po>1){
            ans+=((po-1)/k);
            int temp=who[po-1];
            pos[x]=po-1;
            pos[temp]=po;
            who[po-1]=x;
            who[po]=temp;
        }
    }
    printf("%I64d",ans);
}