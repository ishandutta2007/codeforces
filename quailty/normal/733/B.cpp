#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int l[MAXN],r[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]);
    int suml=0,sumr=0;
    for(int i=1;i<=n;i++)
        suml+=l[i],sumr+=r[i];
    int res=0,mx=abs(suml-sumr);
    for(int i=1;i<=n;i++)
    {
        suml-=l[i],sumr-=r[i];
        suml+=r[i],sumr+=l[i];
        if(mx<abs(suml-sumr))
        {
            mx=abs(suml-sumr);
            res=i;
        }
        suml-=r[i],sumr-=l[i];
        suml+=l[i],sumr+=r[i];
    }
    return 0*printf("%d",res);
}