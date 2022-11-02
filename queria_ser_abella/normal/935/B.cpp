#include <bits/stdc++.h>

char ch[100100];

main(){
    int n,ans;
    scanf("%d",&n);
    ans = 0;
    for(int i=0;i<n;i++)
        scanf(" %c",ch+i);
    int x=0, y=0;
    for(int i=0;i<n;i++){
        if(ch[i] == 'U') x++;
        else y++;
        if(x == y && i != n-1 && ch[i] == ch[i+1]) ans++;
    }
    printf("%d\n",ans);
}