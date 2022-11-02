#include<bits/stdc++.h>
#define MAXN 1000010
#define LL long long
using namespace std;
int ans,n,a[MAXN],d[MAXN];
LL k;
int check(int x){
    LL sum=0;
    for (int i=0;i<n;i++){
        while ((d[i])&&((a[i]>>d[i])<x)) d[i]--;
        while ((a[i]>>(d[i]+1))>=x) d[i]++;
        if ((a[i]>>d[i])>=x){
            int o=a[i]-((a[i]>>d[i])<<d[i]);
            sum+=(1<<d[i]);
            if (((a[i]>>d[i])+1)>>1>=x) sum+=o;
        }
    }
    return (sum>=k);
}
int main(){
    scanf("%d%lld",&n,&k);
    ans=-1;
    int l=1,r=0;
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        r=max(r,a[i]);
    }
    while (l<=r){
        int mid=(l+r)>>1;
        if (check(mid)){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    printf("%d\n",ans);
}