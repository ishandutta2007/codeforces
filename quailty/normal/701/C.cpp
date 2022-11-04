#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int cnt[52];
int getId(char x)
{
    if(x>='a' && x<='z')return x-'a';
    else return x-'A'+26;
}
int main()
{
    int n,k=0;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
        cnt[getId(s[i])]++;
    for(int i=0;i<52;i++)
        k+=(cnt[i]>0);
    memset(cnt,0,sizeof(cnt));
    int res=n;
    for(int l=0,r=0,t=0;l<n;l++)
    {
        while(r<n && t<k)
        {
            if(cnt[getId(s[r])]++==0)t++;
            r++;
        }
        if(t==k)res=min(res,r-l);
        if(--cnt[getId(s[l])]==0)t--;
    }
    printf("%d\n",res);
    return 0;
}