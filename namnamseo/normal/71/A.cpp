#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    char buf[200];
    for(;n--;){
        scanf("%s",buf);
        int i;
        for(i=0;buf[i];i++);
        if(i>10){
            printf("%c%d%c\n",buf[0],i-2,buf[i-1]);
        } else puts(buf);
    }
    return 0;
}