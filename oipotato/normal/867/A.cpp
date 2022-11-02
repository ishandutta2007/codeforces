#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int fa[1010];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool check(int x1,int y1,int x2,int y2){return x1*y2==y1*x2;}
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int n;char s[110];scanf("%d%s",&n,s+1);
        int ans=0;
        rep(i,n-1)if(s[i]=='S'&&s[i+1]=='F')ans++;else if(s[i]=='F'&&s[i+1]=='S')ans--;
        puts(ans>0?"YES":"NO");
    }
    return 0;
}