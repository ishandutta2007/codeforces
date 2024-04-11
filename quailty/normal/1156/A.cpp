#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==1)
        {
            if(a[i+1]==2)res+=3;
            else res+=4;
        }
        else if(a[i]==2)
        {
            if(a[i+1]==1)res+=3;
            else return 0*printf("Infinite\n");
        }
        else
        {
            if(a[i+1]==1)res+=4;
            else return 0*printf("Infinite\n");
        }
    }
    for(int i=1;i<n-1;i++)
        res-=(a[i]==3 && a[i+1]==1 && a[i+2]==2);
    printf("Finite\n");
    printf("%d\n",res);
    return 0;
}