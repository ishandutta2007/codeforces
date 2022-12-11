#include<bits/stdc++.h>
#define N 200010
#define M 2000010
#define mod 1000000007
#define mp make_pair
#define PII pair<int,int>
using namespace std;
int n,m,i,j,k,pp,x;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        pp=0;
        for(j=1;j<=k;j++)
        {
            scanf("%d",&x);
            if(x==pp+1)pp++,n--;
        }
    }
    printf("%d\n",(n<<1)-m+1);
}