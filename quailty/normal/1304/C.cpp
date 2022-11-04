#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int t[MAXN],l[MAXN],r[MAXN];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&t[i],&l[i],&r[i]);
        int nl=m,nr=m,isok=1;
        for(int i=1;i<=n && isok;i++)
        {
            nl-=t[i]-t[i-1];
            nr+=t[i]-t[i-1];
            nl=max(nl,l[i]);
            nr=min(nr,r[i]);
            isok&=(nl<=nr);
        }
        printf("%s\n",(isok ? "YES" : "NO"));
    }
    return 0;
}