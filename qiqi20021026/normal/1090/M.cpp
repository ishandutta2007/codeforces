#include<bits/stdc++.h>
using namespace std;

int n,m,a[1000009];
int main(){
    scanf("%d%d",&n,&m);
    int i,ans=0,now=0;
    for (i=1; i<=n; i++){
        scanf("%d",&a[i]);
        if (i>1 && a[i]==a[i-1]) now=0; now++;
        ans=max(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}