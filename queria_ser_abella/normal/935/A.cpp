#include <bits/stdc++.h>

main(){
    int n,ans;
    scanf("%d",&n);
    ans = 0;
    for(int i=1;i<n;i++){
        if((n-i)%i == 0)
        ans++;
    }
    printf("%d",ans);
}