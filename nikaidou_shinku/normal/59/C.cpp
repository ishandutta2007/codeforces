#include <bits/stdc++.h>
using namespace std;
char ch[105];
int k,i,j,len,pos[30],L[105],cnt;
int main()
{
    scanf("%d", &k);
    scanf("%s", ch);
    len = strlen(ch);
    memset(pos, 0, sizeof(pos));
    for(i = 0, cnt = 0, j = len - 1; i <= j; i ++, j --)
    {
        if(ch[i] != '?' && ch[j] != '?')
        {
            if(ch[i] != ch[j])  break;
            else if(ch[i] - 'a' + 1 > k) break;
            else pos[ch[i] - 'a' + 1] = 1;
        }
        else
        {
            if(ch[i] == '?' && ch[j] != '?')
            {
                ch[i] = ch[j];
                pos[ch[i] - 'a' + 1] = 1;
                if(ch[j] - 'a' + 1 > k) break;
            }
            else if(ch[j] == '?' && ch[i] != '?')
            {
                ch[j] = ch[i];
                pos[ch[i] - 'a' + 1] = 1;
                if(ch[i] - 'a' + 1 > k) break;
            }
            else L[cnt ++] = i;
        }
    }
    if(i<j) printf("IMPOSSIBLE\n");
    else
    {
        for(i=cnt-1;i>=0;i--)
        {
            for(j=k;j>=1;j--)
                if(pos[j]==0)
                {
                    ch[L[i]]=ch[len-1-L[i]]='a'+j-1;
                    pos[j]=1;
                    break;
                }
            if(j==0)   ch[L[i]]=ch[len-1-L[i]]='a';
        }
        for(j=1;j<=k;j++)
            if(pos[j]==0)
                break;
        if(j<=k) printf("IMPOSSIBLE\n");
        else printf("%s\n",ch);
    }
    return 0;
}