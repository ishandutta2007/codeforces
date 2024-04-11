#include <cstdio>
int abs(int x){return x>0?x:-x;}
int main()
{
    int a,b,s;
    scanf("%d%d%d",&a,&b,&s);
    puts(((1&(a+b-s | abs(a)+abs(b)>s))<<2)+"Yes\0No");
    return 0;
}