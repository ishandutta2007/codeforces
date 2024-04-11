#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char s[200005],t[200005];
int c[30][30];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s%s",s,t);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            cnt++;
            if(!c[s[i]-'a'][t[i]-'a'])
            {
                c[s[i]-'a'][t[i]-'a']=i+1;
            }
        }
    }
    bool isok=0;
    for(int i=0;i<26;i++)
    {
        if(isok)break;
        for(int j=i+1;j<26;j++)
        {
            if(c[i][j] && c[j][i])
            {
                printf("%d\n%d %d\n",cnt-2,c[i][j],c[j][i]);
                isok=1;
                break;
            }
        }
    }
    if(!isok)
    {
        for(int i=0;i<26;i++)
        {
            if(isok)break;
            for(int j=i+1;j<26;j++)
            {
                if(isok)break;
                for(int k=0;k<26;k++)
                {
                    if(c[i][j] && c[k][i])
                    {
                        printf("%d\n%d %d\n",cnt-1,c[i][j],c[k][i]);
                        isok=1;
                        break;
                    }
                    if(c[i][j] && c[j][k])
                    {
                        printf("%d\n%d %d\n",cnt-1,c[i][j],c[j][k]);
                        isok=1;
                        break;
                    }
                }
            }
        }
    }
    if(!isok)
    {
        printf("%d\n-1 -1\n",cnt);
    }
    return 0;
}