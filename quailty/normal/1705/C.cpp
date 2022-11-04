#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int MAXC=45;
char s[MAXN];
ll l[MAXC],r[MAXC],len[MAXC];
int solve()
{
    int n,c,q;
    scanf("%d%d%d%s",&n,&c,&q,s);
    len[0]=strlen(s);
    for(int i=1;i<=c;i++)
    {
        scanf("%lld%lld",&l[i],&r[i]),l[i]--,r[i]--;
        len[i]=len[i-1]+r[i]-l[i]+1;
    }
    while(q--)
    {
        ll k;
        scanf("%lld",&k),k--;
        for(int i=c;i>=1;i--)
            if(k>=len[i-1])k=k-len[i-1]+l[i];
        printf("%c\n",s[k]);
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}