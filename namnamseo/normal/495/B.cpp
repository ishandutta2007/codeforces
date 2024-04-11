#include <cstdio>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a<b) {
        puts("0");
        return 0;
    }
    a-=b;
    if(a==0){
        puts("infinity");
    } else {
        int ans=0;
        int i;
        for(i=1;i*i<=a;++i){
            if(!(a%i)){
                if(i>b) ++ans;
                if(a/i!=i && a/i>b) ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}