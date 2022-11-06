#include <cstdio>

int n;

int basedata,buf;

int dis(int x)
{
    while((x%2)==0) x>>=1;
    while((x%3)==0) x/=3;
    return x;
}

int main()
{
    scanf("%d%d",&n,&basedata);
    basedata=dis(basedata);
    for(;--n;){
        scanf("%d",&buf); buf=dis(buf); if(buf!=basedata){
            puts("No"); return 0;
        }
    }
    puts("Yes");
    return 0;
}