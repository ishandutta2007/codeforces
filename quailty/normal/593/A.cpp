#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105][1005];
int len[105],cnt[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        len[i]=strlen(s[i]);
        for(int j=0;j<len[i];j++)
            cnt[i]|=(1<<(s[i][j]-'a'));
    }
    int ans=0;
    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++)
        {
            int now=0,mask=(1<<i)|(1<<j);
            for(int k=0;k<n;k++)
                if((mask|cnt[k])==mask)
                    now+=len[k];
            ans=max(ans,now);
        }
    printf("%d\n",ans);
    return 0;
}