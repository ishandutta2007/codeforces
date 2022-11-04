#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
char str[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%s",str+1);
    for(int i=1,j=1;i<n;i=j)
    {
        while(j<n && str[i]==str[j])j++;
        if(str[i]=='1')sort(a+i,a+j+1);
    }
    for(int i=1;i<=n;i++)
        if(a[i]!=i)return 0*printf("NO\n");
    return 0*printf("YES\n");
}