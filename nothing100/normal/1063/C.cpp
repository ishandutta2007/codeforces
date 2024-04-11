#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,l[2],r[2];
char ch[15];
int main(){
    scanf("%d",&n);
    l[0]=l[1]=0; r[0]=r[1]=1000000000;
    for (int i=0;i<n;i++){
        printf("%d %d\n",i&1,(l[i&1]+r[i&1])/2);
        fflush(stdout);
        scanf("%s",ch);
        if (ch[0]=='b')
            l[i&1]=(l[i&1]+r[i&1])/2+1;
        else
            r[i&1]=(l[i&1]+r[i&1])/2-1;
    }
    printf("%d %d %d %d\n",0,l[0],1,l[1]);
    fflush(stdout);
}