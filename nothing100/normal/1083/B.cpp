#include<bits/stdc++.h>
#define mp make_pair
#define LL long long
using namespace std;
LL ans;
int n,k;
char a[500050],b[500050];
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",a);
    scanf("%s",b);
    int mid=0,l=0,r=0,same=1;
    for (int i=0;i<n;i++){
        if (same==1){
            if (a[i]!=b[i]){
                same=0;
                l=r=1;
            }
        }
        else{
            mid*=2;
            if (a[i]=='a') mid+=1;
            if (b[i]=='b') mid+=1;
            mid=min(mid,k);
        }
        ans=ans+min(k,mid+l+r+same);
    }
    printf("%lld\n",ans);
}