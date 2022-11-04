#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt[26];
int cnta[26],cntb[26],cntc[26];
char a[100005],b[100005],c[100005];
int main()
{
    scanf("%s%s%s",a,b,c);
    int lena=strlen(a);
    int lenb=strlen(b);
    int lenc=strlen(c);
    for(int i=0;i<lena;i++)
    {
        cnta[a[i]-'a']++;
    }
    for(int i=0;i<lenb;i++)
    {
        cntb[b[i]-'a']++;
    }
    for(int i=0;i<lenc;i++)
    {
        cntc[c[i]-'a']++;
    }
    int up=lena/lenb;
    int ans=0,cb=0,cc=0;
    for(int i=0;i<=up;i++)
    {
        memcpy(cnt,cnta,sizeof(cnta));
        bool isok=1;
        for(int j=0;j<26;j++)
        {
            if(i*cntb[j]>cnta[j])
            {
                isok=0;
                break;
            }
            cnt[j]-=i*cntb[j];
        }
        if(!isok)continue;
        int t=200000;
        for(int j=0;j<26;j++)
        {
            if(cntc[j]==0)continue;
            t=min(t,cnt[j]/cntc[j]);
        }
        if(i+t>ans)
        {
            ans=i+t;
            cb=i;
            cc=t;
        }
    }
    //printf("%d %d %d\n",cb,cc,ans);
    for(int i=1;i<=cb;i++)
    {
        printf("%s",b);
    }
    for(int i=1;i<=cc;i++)
    {
        printf("%s",c);
    }
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<=cnta[i]-cb*cntb[i]-cc*cntc[i];j++)
        {
            printf("%c",'a'+i);
        }
    }
    return 0;
}