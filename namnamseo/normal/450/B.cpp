#include <cstdio>

int main()
{
    int data[6];
    int x,y,n;
    scanf("%d%d%d",&x,&y,&n);
    n--;
    data[0]=x;
    data[1]=y;
    data[2]=y-x;
    for(int i=3;i<6;i++) data[i]=-data[i-3];
    x = data[n%6];
    int mod = 1000000007;
    if(x<0){
        x=-x; x%=mod; x=mod-x;
    }
    x%=mod;
    printf("%d\n",x);
    return 0;
}