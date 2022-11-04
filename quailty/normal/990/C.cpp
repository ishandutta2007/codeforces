#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
char buff[MAXN];
string str[MAXN];
int cnt[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",buff);
        str[i]=buff;
    }
    for(int i=1;i<=n;i++)
    {
        int now=0,mi=0;
        for(int j=0;j<(int)str[i].size();j++)
        {
            if(str[i][j]=='(')now++;
            else now--;
            mi=min(mi,now);
        }
        if(mi>=0)cnt[now]++;
    }
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        int now=0,mi=0;
        for(int j=(int)str[i].size()-1;j>=0;j--)
        {
            if(str[i][j]==')')now++;
            else now--;
            mi=min(mi,now);
        }
        if(mi>=0)res+=cnt[now];
    }
    printf("%lld\n",res);
    return 0;
}