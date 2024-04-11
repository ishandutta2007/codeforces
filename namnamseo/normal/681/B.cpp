#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    int a=1234567, b=123456, c=1234;
    int i,j,k;
    for(i=0; i*a<=n; ++i){
        for(j=0; a*i+b*j<=n; ++j){
            int tmp=n-a*i-b*j;
            if(tmp%c==0){
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}