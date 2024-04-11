#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int solve()
{
    int n;
    scanf("%d%s",&n,s);
    if(s[0]<'9')
    {
        for(int i=0;i<n;i++)
            s[i]=('9'-s[i])+'0';
    }
    else
    {
        int p=0;
        for(int i=n-1;i>=0;i--)
        {
            s[i]='1'-p-s[i],p=0;
            if(s[i]<0)s[i]+=10,p++;
            s[i]+='0';
        }
    }
    return 0*printf("%s\n",s);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}