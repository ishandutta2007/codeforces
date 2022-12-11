#include<cstdio>
using namespace std;
int n,k,i;
int main()
{
    scanf("%d%d",&n,&k);
    if(k>n||(k==1&&n>1)){puts("-1");return 0;}
    for(i=1;i<=n-k+2&&i<=n;i++)if(i&1)putchar('a');else putchar('b');
    for(i=n-k+3;i<=n;i++)putchar('b'+i-n+k-2);puts("");
}