#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;
int n,m,a[1010],b[1010];
int check(double x){
    for (int i=0;i<n;i++){
        x-=(m+x)/a[i];
        if (x<0) return 0;
        x-=(m+x)/b[(i+1)%n];
        if (x<0) return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    double l=0,r=1000000010,mid,ans=1000000010;
    while (l+eps<r){
        mid=(l+r)/2;
        if (check(mid)){
            r=mid;
            ans=mid;
        }
        else l=mid;
    }
    if (ans>1000000001) printf("-1\n");
    else printf("%.8f\n",ans);
}