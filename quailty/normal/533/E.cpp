#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005],t[100005];
char ss[100005],tt[100005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s%s",s,t);
    if(n==1)printf("2\n");
    else
    {
        int cnt=n;
        int first=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=t[i])
            {
                cnt--;
                first=i;
            }
        }
        if(cnt==n-1)printf("2\n");
        else
        {
            int loc=0;
            for(int i=0;i<n;i++)
            {
                if(i!=first)
                {
                    ss[loc]=s[i];
                    tt[loc++]=t[i];
                }
            }
            int ans=0;
            loc=0;
            for(int i=0;i<n;i++)
            {
                if(ss[loc]==t[i])loc++;
            }
            if(loc==n-1)ans++;
            loc=0;
            for(int i=0;i<n;i++)
            {
                if(tt[loc]==s[i])loc++;
            }
            if(loc==n-1)ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}