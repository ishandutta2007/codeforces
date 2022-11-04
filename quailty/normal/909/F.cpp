#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int res[MAXN];
int subtask1(int n)
{
    if(n&1)return 0*printf("NO\n");
    int tn=n;
    for(int i=1;i<=tn;i++)
        res[i]=i;
    while(n)
    {
        int b=1,t=n;
        while(t>1)t>>=1,b<<=1;
        for(int i=b,j=b-1;i<=n;i++,j--)
            swap(res[i],res[j]);
        n-=2*(n-b+1);
    }
    printf("YES\n");
    for(int i=1;i<=tn;i++)
        printf("%d%c",res[i]," \n"[i==n]);
    printf("\n");
}
int subtask2(int n)
{
    if(n<6 || (n&(n-1))==0)return 0*printf("NO\n");
    printf("YES\n");
    if(n&1)
    {
        printf("3 6 1 5 4 7 2");
        for(int i=8;i<=n;i+=2)
            printf(" %d %d",i+1,i);
        printf("\n");
    }
    else
    {
        printf("3 6 1 5 4 2");
        for(int i=8;i<=n;i+=2)
        {
            if((i&(i-1))==0)
            {
                printf(" %d %d %d %d",i+1,i+2,i-1,i);
                i+=2;
            }
            else printf(" %d %d",i,i-1);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    subtask1(n);
    subtask2(n);
    return 0;
}