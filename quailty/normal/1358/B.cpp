#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int k=0;
        for(int i=1;i<=n;i++)
            if(a[i]<=i)k=i;
        printf("%d\n",k+1);
    }
    return 0;
}