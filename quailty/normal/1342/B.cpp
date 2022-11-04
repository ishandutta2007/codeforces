#include <bits/stdc++.h>
using namespace std;
char str[105];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int n=strlen(str),cnt[2]={0,0};
        for(int i=0;i<n;i++)
            cnt[str[i]-'0']++;
        if(!cnt[0] || !cnt[1])
            printf("%s\n",str);
        else
        {
            for(int i=0;i<n;i++)
                printf("01");
            printf("\n");
        } 
    }
    return 0;
}