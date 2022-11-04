#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
char str[MAXN];
int solve()
{
    scanf("%s",str);
    int n=strlen(str);
    int l_1=0,f_0=n-1;
    for(int i=0;i<n;i++)
        if(str[i]=='1')l_1=i;
    for(int i=n-1;i>=0;i--)
        if(str[i]=='0')f_0=i;
    return 0*printf("%d\n",f_0-l_1+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}