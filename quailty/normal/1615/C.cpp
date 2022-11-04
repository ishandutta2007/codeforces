#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char s[MAXN],t[MAXN];
int solve()
{
    int n,res=MAXN;
    scanf("%d%s%s",&n,s,t);
    { // even
        int cnt[2]={0,0};
        for(int i=0;i<n;i++)
            if(s[i]!=t[i])cnt[s[i]-'0']++;
        if(cnt[0]==cnt[1])res=min(res,cnt[0]+cnt[1]);
    }
    { // odd
        for(int i=0;i<n;i++)
            t[i]='0'+'1'-t[i];
        int cnt[2]={0,0};
        for(int i=0;i<n;i++)
            if(s[i]!=t[i])cnt[s[i]-'0']++;
        if(cnt[0]+1==cnt[1])res=min(res,cnt[0]+cnt[1]);
    }
    return 0*printf("%d\n",res<MAXN ? res : -1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}