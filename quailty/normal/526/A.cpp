#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    bool isok=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*')
        {
            for(int j=1;j<n;j++)
            {
                int k;
                for(k=0;k<=4 && i+j*k<n;k++)
                {
                    if(s[i+j*k]=='.')break;
                }
                if(k==5)isok=1;
            }
        }
    }
    if(isok)printf("yes");
    else printf("no");
    return 0;
}