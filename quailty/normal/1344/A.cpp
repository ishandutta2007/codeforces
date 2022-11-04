#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            a[i]=((i+a[i])%n+n)%n;
        sort(a,a+n);
        bool isok=1;
        for(int i=0;i<n;i++)
            isok&=(a[i]==i);
        printf("%s\n",(isok ? "YES" : "NO"));
    }
    return 0;
}