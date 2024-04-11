#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[200005];
int d[200005];
bool used[200005];
int main()
{
    int m;
    scanf("%s",s);
    int n=strlen(s);
    scanf("%d",&m);
    int a;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a);
        d[a-1]^=1;
    }
    int tot=0;
    for(int i=0;i<n/2;i++)
    {
        tot^=d[i];
        if(tot)
        {
            printf("%c",s[n-i-1]);
            used[n-i-1]=1;
        }
        else
        {
            printf("%c",s[i]);
            used[i]=1;
        }
    }
    for(int i=n/2;i<n;i++)
    {
        if(used[i])
        {
            printf("%c",s[n-i-1]);
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}