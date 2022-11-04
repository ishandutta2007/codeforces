#include <bits/stdc++.h>
char a[100];
int main(){
    int n;
    scanf("%d" ,&n);
    fgetc(stdin);
    int ans=0;
    for(int i=1;i<=n;i++){
        fgets(a,100,stdin);
       // fgetc(stdin);
       // printf("%c\n" ,a[0]);
        if(a[0]=='T')
            ans+=4;
        if(a[0]=='C')
            ans+=6;
        if(a[0]=='O')
            ans+=8;
        if(a[0]=='D')
            ans+=12;
        if(a[0]=='I')
            ans+=20;
    }
    printf("%d" ,ans);
    return 0;
}