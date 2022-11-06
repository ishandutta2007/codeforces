#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
for(;n--;){
    char buf[20];
    int a,b;
    scanf("%s%d%d",buf,&a,&b);
    if(a>=2400 && a<b){
        puts("YES");
        return 0;
    }
}
    puts("NO");
    return 0;
}