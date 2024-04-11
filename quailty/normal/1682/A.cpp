#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int solve()
{
    int n;
    scanf("%d%s",&n,s);
    int res=0;
    for(int i=n/2;i<n;i++)
    {
        if(s[i]!=s[n/2])break;
        res+=1+(i>n-1-i);
    }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}