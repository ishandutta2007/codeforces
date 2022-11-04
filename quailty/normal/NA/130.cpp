#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    sort(a+1,a+n+1);
    int res=0;
    for(int i=1;i<=n && 10*sum<45*n;i++)
    {
        sum+=5-a[i];
        res++;
    }
    return 0*printf("%d\n",res);
}