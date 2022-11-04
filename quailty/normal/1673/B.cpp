#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
char str[MAXN];
int solve()
{
    scanf("%s",str+1);
    int n=strlen(str+1),c=n;
    int las[26]={0};
    for(int i=1;i<=n;i++)
    {
        if(las[str[i]-'a'])
        {
            c=i-las[str[i]-'a'];
            break;
        }
        las[str[i]-'a']=i;
    }
    for(int i=1;i+c<=n;i++)
        if(str[i]!=str[i+c])
            return 0*printf("NO\n");
    return 0*printf("YES\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}