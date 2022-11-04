#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005];
int main()
{
    int n;
    scanf("%d%s",&n,s);
    int res=n;
    for(int _=0;_<2;_++)
    {
        int cnt[2]={0,0};
        for(int i=0;i<n;i++)
        {
            if(i%2==_ && s[i]=='r')cnt[0]++;
            if(i%2==1-_ && s[i]=='b')cnt[1]++;
        }
        res=min(res,max(cnt[0],cnt[1]));
    }
    printf("%d\n",res);
    return 0;
}