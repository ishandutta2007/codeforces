# include <cstdio>

int main()
{
    int a,b,c,d,n;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
    
    int ret=0;
    for(int i=1;i<=n;i++)
        if(i%a==0||i%b==0||i%c==0||i%d==0)ret++;
    printf("%d\n",ret);
}