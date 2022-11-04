#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[50005];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i+26<=n;i++)
    {
        int cnt[26]={0};
        for(int j=0;j<26;j++)if(s[i+j]!='?')
            cnt[s[i+j]-'A']++;
        bool isok=1;
        for(int j=0;j<26;j++)
            isok&=(cnt[j]<2);
        if(isok)
        {
            for(int j=0;j<26;j++)if(s[i+j]=='?')
                for(int k=0;k<26;k++)if(!cnt[k])
                {
                    s[i+j]='A'+k,cnt[k]++;
                    break;
                }
            for(int j=0;j<n;j++)
                if(s[j]=='?')s[j]='A';
            return 0*printf("%s",s);
        }
    }
    return 0*printf("-1");
}