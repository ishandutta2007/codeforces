#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n,k,a[2001],i;
    long long ans=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]--;
    }
    sort(a,a+n);
    for(i=0;i<n/2;i++){
        int temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1]=temp;
    }
    for(i=0;i<n;i+=k){
            ans+=a[i]*2;  
    }
    printf("%I64d",ans);
}