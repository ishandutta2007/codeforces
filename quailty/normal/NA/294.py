#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int x[MAXN];
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    int res=2;
    for(int i=1;i<n;i++)
    {
        if(x[i+1]-x[i]>=2*d)res++;
        if(x[i+1]-x[i]>2*d)res++;
    }
    printf("%d\n",res);
    return 0;
}