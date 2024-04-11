#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 404;
const short inf = 2000;
 
char s[N], t[N];
short dp[N][N][N], vis[N][N][N],cn,ls,lt;
 
short rec(int p,int i,int j)
{
    if (p==ls){
        if (i==lt || j==lt) return 0;
        return -inf; 
    }
    short &ret = dp[p][i][j];
    short &vs = vis[p][i][j];
    if (vs==cn) return ret;
    vs = cn;
    ret = -inf;
    int x = 0;
    if (i<lt && s[p]==t[i]) x = 1,ret = max(ret,(short) (rec(p+1,i+1,j)+1));
    if (j<lt && s[p]==t[j]) x = 1,ret = max(ret, (short)(rec(p+1,i,j+1)+1));
    if (!x) ret = rec(p+1,i,j);
    return ret;
}
 
int main()
{
    int tc; scanf("%d",&tc);
    while (tc--)
    {
        scanf("%s%s",s,t);
        ls = strlen(s);
        lt = strlen(t);
        int mx = 0;
        cn++;
        for (int i = 0;i<lt;i++)
            mx = max(mx, (int)rec(0,0,i));
        if (mx>=lt) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}