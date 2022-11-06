#include <cstdio>

char buf[120];
int n;

int main()
{
    scanf("%d%s",&n,buf);
    int i,j,k;
    for(i=0;i<n;++i){
        if(buf[i]=='*')
        for(j=1;i+j*4<n;++j){
            for(k=1;k<=4;++k){
                if(buf[i+j*k]!='*') break;
            }
            if(k==5){
                puts("yes"); return 0;
            }
        }
    }
    puts("no");
    return 0;
}