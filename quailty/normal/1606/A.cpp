#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        static char str[105];
        scanf("%s",str);
        int n=strlen(str);
        int cnt[2]={0,0};
        for(int i=1;i<n;i++)
        {
            if(str[i-1]=='a' && str[i]=='b')cnt[0]++;
            if(str[i-1]=='b' && str[i]=='a')cnt[1]++;
        }
        if(cnt[0]<cnt[1])str[0]='a';
        if(cnt[0]>cnt[1])str[0]='b';
        printf("%s\n",str);
    }
    return 0;
}