#include <cstdio>

int data[10];
int len;

int max(int a,int b) { return a>b?a:b; }

int main()
{
    int i,j;
    int n;
    scanf("%d",&n);
    for(len=0;n;++len){
        data[len]=n%10;
        n/=10;
    }
    int k=0;
    for(i=0;i<len;++i) k=max(k,data[i]);
    printf("%d\n",k);
    bool started;
    for(i=1;i<=k;++i){
        started=false;
        for(j=0;j<len;++j){
            if(i<=data[len-1-j]){
                started=true;
                putchar('1');
            } else if(started) putchar('0');
        }
        putchar(' ');
    }
    return 0;
}