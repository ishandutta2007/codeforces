#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,p[200010];
        char s[200010];
        scanf("%d",&n);
        rep(i,n)scanf("%d",&p[i]);
        scanf("%s",s+1);
        int q[200010];
        rep(i,n)q[i]=i;
        sort(q+1,q+n+1,[&](int x,int y){return s[x]==s[y]?p[x]<p[y]:s[x]<s[y];});
        rep(i,n)p[q[i]]=i;
        rep(i,n)printf("%d%c",p[i]," \n"[i==n]);
    }
    return 0;
}