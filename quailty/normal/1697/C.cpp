#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char s[MAXN],t[MAXN];
int solve()
{
    int n;
    scanf("%d%s%s",&n,s,t);
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i])continue;
        int now=-1;
        if(s[i]=='a' && t[i]=='b')
        {
            while(now!=0 && ++i<n && s[i]!='c' && t[i]!='c')now+=s[i]-t[i];
            if(now!=0)return 0*printf("NO\n");
        }
        else if(s[i]=='b' && t[i]=='c')
        {
            while(now!=0 && ++i<n && s[i]!='a' && t[i]!='a')now+=s[i]-t[i];
            if(now!=0)return 0*printf("NO\n");
        }
        else return 0*printf("NO\n");
    }
    return 0*printf("YES\n");
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)solve();
    return 0;
}