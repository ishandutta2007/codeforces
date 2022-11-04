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
        printf("%d\n",unique(a+1,a+n+1)-(a+1));
    }
    return 0;
}