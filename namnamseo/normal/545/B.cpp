#include <cstdio>

char a[100010];
char b[100010];
int n;
int p,q;

int main()
{
    scanf("%s%s",a,b);
    for(n=0;a[n];++n) a[n]-=48, b[n]-=48, p+=(a[n]==1 && b[n]==0), q+=(a[n]==0 && b[n]==1);
    if((p-q)%2) puts("impossible");
    else {
        int i;
        p=(p+q)/2;
        for(i=0;i<n;++i){
            if(a[i]==b[i]) putchar('0');
            else {
                if(p>0){
                    putchar(49-a[i]);
                    --p;
                }
                else {
                    putchar(48+a[i]);
                }
            }
        }
        putchar(10);
    }
    return 0;
}