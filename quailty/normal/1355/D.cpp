#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int a[MAXN];
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    if(s>=2*n)
    {
        printf("YES\n");
        for(int i=1;i<n;i++)
            printf("2 ");
        printf("%d\n",s-2*n+2);
        printf("1\n");
    }
    else printf("NO\n");
    return 0;
}