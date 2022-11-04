#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char s[MAXN],t[MAXN];
int go[MAXN][26];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s+1,t);
        int n=strlen(s+1),nxt[26];
        for(int i=0;i<26;i++)
            nxt[i]=n+1;
        for(int i=n;i>=0;i--)
        {
            memcpy(go[i],nxt,sizeof(nxt));
            if(i)nxt[s[i]-'a']=i;
        }
        int res=1,cur=0;
        for(int i=0;t[i];i++)
        {
            if(go[cur][t[i]-'a']>n)cur=0,res++;
            if(go[cur][t[i]-'a']>n){res=-1; break;}
            cur=go[cur][t[i]-'a'];
        }
        printf("%d\n",res);
    }
    return 0;
}