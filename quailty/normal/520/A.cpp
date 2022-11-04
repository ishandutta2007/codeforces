#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int cnt[30];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            cnt[s[i]-'a']++;
        else cnt[s[i]-'A']++;
    }
    bool isok=1;
    for(int i=0;i<26;i++)
    {
        if(cnt[i]==0)
        {
            isok=0;
            break;
        }
    }
    if(isok)printf("YES");
    else printf("NO");
    return 0;
}