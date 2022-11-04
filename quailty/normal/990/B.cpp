#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN],b[MAXN];
int main()
{
    int n,K;
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int res=0;
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n && a[i]==a[j])j++;
        if(j>n || a[i]+K<a[j])res+=j-i;
    }
    printf("%d\n",res);
    return 0;
}