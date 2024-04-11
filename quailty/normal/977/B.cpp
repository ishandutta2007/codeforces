#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
char str[MAXN];
int main()
{
    int n;
    scanf("%d%s",&n,str);
    int mx=0,loc=0;
    for(int i=0;i+1<n;i++)
    {
        int cnt=0;
        for(int j=0;j+1<n;j++)
            cnt+=(str[i]==str[j] && str[i+1]==str[j+1]);
        if(mx<cnt)mx=cnt,loc=i;
    }
    printf("%c%c",str[loc],str[loc+1]);
    return 0;
}