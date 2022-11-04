#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char s[2][MAXN];
char ans[MAXN];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    scanf("%s%s",s[0],s[1]);
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(s[0][i]==s[1][i])y++;
        else x++;
    }
    if(t<(x+1)/2)printf("-1\n");
    else
    {
        int a,d,b;
        if(t>=x)
        {
            a=0;
            d=t-x;
            b=0;
        }
        else
        {
            d=0;
            a=x-t;
            b=a;
        }
        for(int i=0;i<n;i++)
        {
            if(s[0][i]==s[1][i])
            {
                if(d>0)
                {
                    ans[i]=(s[0][i]-'a'+1)%26+'a';
                    d--;
                }
                else ans[i]=s[0][i];
            }
            else
            {
                if(a>0)
                {
                    ans[i]=s[1][i];
                    a--;
                }
                else if(b>0)
                {
                    ans[i]=s[0][i];
                    b--;
                }
                else
                {
                    for(int j=0;j<26;j++)
                        if(s[0][i]!='a'+j && s[1][i]!='a'+j)
                        {
                            ans[i]='a'+j;
                            break;
                        }
                }
            }
        }
        printf("%s\n",ans);
    }
    return 0;
}