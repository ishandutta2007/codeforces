#include <cstdio>

char a[101];
char b[101];
char c[101];

int strlen(char* a){
    int i;
    for(i=0;*(a+i);++i);
    return i;
}

bool can(int p,int q,int r)
{
    if(p && q && r && p+q == r){
        for(;p--;) putchar('|'); putchar('+');
        for(;q--;) putchar('|'); putchar('=');
        for(;r--;) putchar('|');
        putchar(10);
        return true;
    }
    return false;
}

int main()
{
    scanf("%[^+]+%[^=]=%s",a,b,c);
    int x=strlen(a);
    int y=strlen(b);
    int z=strlen(c);
    if(can(x,y,z) || can(x-1,y+1,z) || can(x-1,y,z+1) || can(x+1,y-1,z) || can(x,y-1,z+1) || can(x+1,y,z-1) || can(x,y+1,z-1)) 0;
    else puts("Impossible");
    return 0;
}