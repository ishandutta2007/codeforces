#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105][105];
int G[30][30],C[30][30],in[30];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    bool isok=1;
    for(int i=0;i<n-1;i++)
    {
        int lenx=strlen(s[i]);
        int leny=strlen(s[i+1]);
        bool flag=1;
        for(int j=0;j<min(lenx,leny);j++)
        {
            if(s[i][j]!=s[i+1][j])
            {
                if(!G[s[i][j]-'a'][s[i+1][j]-'a'])
                {
                    G[s[i][j]-'a'][s[i+1][j]-'a']=1;
                    in[s[i+1][j]-'a']++;
                }
                flag=0;
                break;
            }
        }
        if(flag)
        {
            if(lenx>leny)isok=0;
        }
    }
    if(isok)
    {
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                C[i][j]=G[i][j];
            }
        }
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    C[i][j]=C[i][j] || (C[i][k] && C[k][j]);
                }
            }
        }
        for(int i=0;i<26;i++)
        {
            if(C[i][i])
            {
                isok=0;
                break;
            }
        }
    }
    if(isok)
    {
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(in[j]==0)
                {
                    in[j]=-1;
                    printf("%c",j+'a');
                    for(int k=0;k<26;k++)
                    {
                        if(G[j][k]==1)
                        {
                            G[j][k]=0;
                            in[k]--;
                        }
                    }
                    break;
                }
            }
        }
    }
    else printf("Impossible\n");
}