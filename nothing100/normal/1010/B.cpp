#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;
int m,n,seq[66];
int main(){
    scanf("%d%d",&m,&n);
    for (int i=0;i<n;i++){
        printf("%d\n",1);
        fflush(stdout);
        scanf("%d",&seq[i]);
        if (seq[i]==0) exit(0);
    }
    int l=2,r=m,mid,ans,cs=0;
    while (l<=r){
        mid=(l+r)/2;
        printf("%d\n",mid);
        fflush(stdout);
        scanf("%d",&ans);
        ans=ans*seq[cs%n];
        if (ans==0) exit(0);
        else if (ans==1) l=mid+1;
        else r=mid-1;
        cs++;
    }
    return 0;
}