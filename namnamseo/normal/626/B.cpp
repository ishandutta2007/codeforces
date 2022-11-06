#include <cstdio>
#define param [a][b][c]

int n;
int r,g,b;

bool chk[201][201][201];
int  dp[201][201][201];

int work(int a,int b,int c){
    if(a+b+c==1){
        if(a) return 1;
        if(b) return 2;
        if(c) return 4;
    }
    if(chk param) return dp param;
    chk param=1;
    int& ret=dp param;
    if(a>=2) ret|=work(a-1,b,c);
    if(b>=2) ret|=work(a,b-1,c);
    if(c>=2) ret|=work(a,b,c-1);
    if(a&&b) ret|=work(a-1,b-1,c+1);
    if(c&&b) ret|=work(a+1,b-1,c-1);
    if(a&&c) ret|=work(a-1,b+1,c-1);
    return ret;
}

int main()
{
    scanf("%d",&n);
    int i;
    char buf;
    for(i=0;i<n;++i){
        do{ buf=getchar(); } while(buf<'A' || buf>'Z');
        if(buf=='R') ++r;
        if(buf=='G') ++g;
        if(buf=='B') ++b;
    }
    int ret=work(r,g,b);
    if(ret&4)putchar('B');
    if(ret&2)putchar('G');
    if(ret&1)putchar('R');
    return 0;
}