#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char a[1005],b[1005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s%s",a,b);
    int tot=0;
    for(int i=0;i<n;i++)
    {
        tot+=min(abs(b[i]-a[i]),10-abs(b[i]-a[i]));
    }
    printf("%d\n",tot);
    return 0;
}