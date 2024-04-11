#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[200005],t[200005];
int s_up[35],s_low[35];
int t_up[35],t_low[35];
int main()
{
    scanf("%s%s",s,t);
    int lens=strlen(s),lent=strlen(t);
    for(int i=0;i<lens;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            s_low[s[i]-'a']++;
        }
        else s_up[s[i]-'A']++;
    }
    for(int i=0;i<lent;i++)
    {
        if(t[i]>='a'&&t[i]<='z')
        {
            t_low[t[i]-'a']++;
        }
        else t_up[t[i]-'A']++;
    }
    int y=0,w=0;
    for(int i=0;i<26;i++)
    {
        int t=min(s_up[i],t_up[i]);
        y+=t;
        s_up[i]-=t;
        t_up[i]-=t;
        t=min(s_low[i],t_low[i]);
        y+=t;
        s_low[i]-=t;
        t_low[i]-=t;
    }
    for(int i=0;i<26;i++)
    {
        if(s_up[i]==0)
        {
            int t=min(s_low[i],t_up[i]);
            w+=t;
        }
        else
        {
            int t=min(s_up[i],t_low[i]);
            w+=t;
        }
    }
    printf("%d %d\n",y,w);
    return 0;
}