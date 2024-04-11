#include <cstdio>

int main()
{
    char buf;
    bool flag=true;
    const int need[3]={5,7,5};
    int sylcount;
    int x;
    for(x=0;x<3;x++){
        sylcount=0;
        while(true){
            buf=getchar();
            if(buf==10 || buf==EOF || !buf) break;
            switch(buf){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                sylcount++;
            default:
                break;
            }
        }
        flag &= (sylcount == need[x]);
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}