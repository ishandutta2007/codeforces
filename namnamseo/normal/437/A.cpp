#include <cstdio>

char data[4][120];
int len[4];

int main()
{
    int i,j;
    for(i=0;i<4;++i) {
        scanf("%s",data[i]);
        for(j=0;data[i][j];++j);
        len[i]=j-2;
    }
    bool a,b;
    int ans=-1;
    for(i=0;i<4;++i){
        a=b=true;
        for(j=0;j<4;++j){
            if(i==j) continue;
            if(!(len[i]>=len[j]*2)) b=false;
            if(!(len[i]*2<=len[j])) a=false;
        }
        if(a || b){
            if(ans==-1) ans=i;
            else {
                puts("C");
                return 0;
            }
        }
    }
    if(ans==-1) putchar('C');
    else putchar(65+ans);
    return 0;
}